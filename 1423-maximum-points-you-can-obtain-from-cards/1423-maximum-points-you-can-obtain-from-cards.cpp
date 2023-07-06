class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       // see also N^2 solution
        
//            Optimised
        int n=cardPoints.size();
        // int sum=accumulate(cardPoints.begin(),cardPoints.begin()+k-1,0);
        int sum=0;
        for(int i=0;i<k;i++)
            sum+=cardPoints[i];
        int maxsum=sum;
        for(int i=k-1;i>=0;i--){
            // cout<<sum;
            sum-=cardPoints[i];
            sum+=cardPoints[n-k+i];
            maxsum=max(sum,maxsum);
        }
        return maxsum;
    }
};