class Solution {
public:
    long long check(vector<int>& piles, int h){
        long long totalhrs=0;
        for(int i=0;i<piles.size();i++){
            totalhrs+=ceil((double)piles[i]/(double)h);
            
        }
        
        return totalhrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=0;
        for(int i=0;i<piles.size();i++){
            high=max(high,piles[i]);
        }
        
        int ans=0;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            long long reqtime=check(piles,mid);
            
            if(reqtime<=h){
                ans=mid;
                high=mid-1;
            }
            else
              low=mid+1;  
        }
        return low;
    }
};