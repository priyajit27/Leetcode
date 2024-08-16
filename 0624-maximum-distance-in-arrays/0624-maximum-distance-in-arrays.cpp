class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int minm=arr[0].front();
        int maxm=arr[0].back();
        int ans=INT_MIN;
        for(int i=1;i<arr.size();i++){
           ans=max(ans,max(abs(arr[i].back()-minm),abs(arr[i].front()-maxm))) ;
            maxm=max(arr[i].back(),maxm);
             minm=min(arr[i].front(),minm);
        }
        return ans;
    }
};