class Solution {
public:
    bool reqtime(vector<int>& dist,double hour,int speedmid){
        double hr=0;
        int n=dist.size();
        for(int i=0;i<n-1;i++){
            if(dist[i]% speedmid==0)
                hr+=dist[i]/speedmid;
            else
                hr+=dist[i]/speedmid +1;
        }
        hr+=(double)dist[n-1]/(double) speedmid;
        if(hr>hour)
            return false;
        return true;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
          int low=1;
          int high=1e7;
          int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(reqtime(dist,hour,mid)){
                ans=mid;
                high=mid-1;
            }
            else
              low=mid+1;  
        }
        return ans;
    }
};