class Solution {
public:
    int candy(vector<int>& rate) {
// //         TC O(N)  SC O(N)
        int n=rate.size();
        vector<int>candy(n,1);
            for(int i=1;i<n;i++){
                if(rate[i]>rate[i-1])
                    candy[i]=candy[i-1]+1;
            }
        
           for(int i=n-2;i>=0;i--){
                if(rate[i]>rate[i+1])
                    candy[i]=max(candy[i+1]+1,candy[i]);
            }
        
        int ans=0;
           for(int i=0;i<n;i++){
                ans+=candy[i];
            }
        return ans;
        
        
        
    }
};