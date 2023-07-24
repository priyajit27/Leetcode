class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
          // using stack
         int n=arr.size();
         int m=1e9+7;
        stack<pair<int,int>>st;
        
         vector<int> pre(n, -1);
        for(int i=0;i<n;i++){
            
            while(!st.empty() && st.top().first>arr[i])
                st.pop();
            
            if(st.size())
                pre[i]=st.top().second;
            st.push({arr[i],i});
        }
        
        while(!st.empty())
            st.pop();
        
          vector<int>nxt(n,n);
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() && st.top().first>=arr[i])
                st.pop();
            
            if(st.size())
                nxt[i]=st.top().second;
            
            st.push({arr[i],i});
        }
        
        
        
             while(!st.empty())
            st.pop();
        
           vector<int> premax(n, -1);
        for(int i=0;i<n;i++){
            
            while(!st.empty() && st.top().first<=arr[i])
                st.pop();
            
            if(st.size())
                premax[i]=st.top().second;
            st.push({arr[i],i});
        }
        
        while(!st.empty())
            st.pop();
        
          vector<int>nxtmax(n,n);
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() && st.top().first<arr[i])
                st.pop();
            
            if(st.size())
                nxtmax[i]=st.top().second;
            
            st.push({arr[i],i});
        }
        
        
        long long ans=0;
        for(int i=0;i<n;i++){
            long left=i-pre[i];
            long right=nxt[i]-i;
             long leftmax=i-premax[i];
            long rightmax=nxtmax[i]-i;
            ans+=(leftmax*rightmax-left*right)*arr[i];
        }
        
        return ans;
    }
};