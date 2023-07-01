class Solution {
public:
    bool check(vector<int>& arr,int day,int m,int k){
        int count=0;
        int num=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=day)
                count++;
            else{
                   num+=(count/k);
                count=0;
            }
        }
        num+=(count/k);
        if(num>=m)
            return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long a=m*1LL *k*1LL;
        if(a>bloomDay.size())
            return -1;
        
          int low=INT_MAX;
        int high=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            high=max(high,bloomDay[i]);
        }
          for(int i=0;i<bloomDay.size();i++){
            low=min(low,bloomDay[i]);
        }
        
        int ans=0;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(check(bloomDay,mid,m,k)){
                ans=mid;
                high=mid-1;
            }
            else
              low=mid+1;  
        }
        return low;
    }
};