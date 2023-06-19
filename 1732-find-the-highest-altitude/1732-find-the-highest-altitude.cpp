class Solution {
public:
    int largestAltitude(vector<int>& gain) {
         int ans=gain[0];
        int maxm=gain[0];
        for(int i=1;i<gain.size();i++){
           ans+=gain[i];
            maxm=max(ans,maxm);
        }
        if(maxm<0)
        return 0;
        return maxm;
    }
};