class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        // N^2 solution
        // int n=arr.size();
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     int minm=INT_MAX;
        //     for(int j=i;j<n;j++){
        //          minm=min(minm,arr[j]);
        //         ans+=minm;
        //     }
        // }
        // return ans;
        
        
        // using stack
         int n=arr.size();
         int m=1e9+7;
        stack<pair<int,int>>st;
        
         vector<int> pre(n, -1);
        for(int i=0;i<n;i++){
            
            while(!st.empty() && st.top().first>=arr[i])
                st.pop();
            
            if(st.size())
                pre[i]=st.top().second;
            st.push({arr[i],i});
        }
        
        while(!st.empty())
            st.pop();
        
          vector<int>nxt(n,n);
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() && st.top().first>arr[i])
                st.pop();
            
            if(st.size())
                nxt[i]=st.top().second;
            
            st.push({arr[i],i});
        }
        
        long long ans=0;
        for(int i=0;i<n;i++){
            long left=i-pre[i];
            long right=nxt[i]-i;
            long total=(left*right)%m;
            ans+=(total*arr[i])%m;
        }
        
        return ans%m;
    }
};