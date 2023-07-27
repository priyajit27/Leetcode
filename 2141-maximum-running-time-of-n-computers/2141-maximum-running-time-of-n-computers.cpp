class Solution {
public:
    bool possible(vector<int>& battery,long long time,long long n){
        long long totaltime=time*n;
        for(long long i:battery)
            totaltime-=min(i,time);
        return totaltime<=0;
    }
    long long maxRunTime(int n, vector<int>& battery) {
        long long low=0;
        // long long high=accumulate(battery.begin(),battery.end(),0);
        long long high=0;
        for(auto i:battery)
            high+=i;
        long long ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(possible(battery,mid,n)){
                ans=mid;
                 low=mid+1;
            }
            else
              high=mid-1; 
        }
        return ans;
    }
};