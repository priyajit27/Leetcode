class Solution {
public:
    bool static sort2(vector<int>a,vector<int>b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& arr) {
         int n=arr.size();
        //[1,2],[2,3],[3,4],[1,3]
        sort(arr.begin(),arr.end(),sort2);
          //[1,2],[1,3],[2,3],[3,4]
        int ans=1;
        int i=1;
        int end=arr[0][1];
       while(i<n){
           if(arr[i][0]>end){
               ans++;
             end=arr[i][1];
           }
           i++;
       }
       return ans;
    }
};