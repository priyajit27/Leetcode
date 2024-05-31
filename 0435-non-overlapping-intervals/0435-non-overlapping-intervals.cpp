class Solution {
public:
//     Time complexity:
// O(N*Logn)

// Space complexity:
// O(1)
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
           int n=arr.size();
        //[1,2],[2,3],[3,4],[1,3]
        sort(arr.begin(),arr.end());
          //[1,2],[1,3],[2,3],[3,4]
        int ans=0;
        int i=1;
        int end=arr[0][1];
       while(i<n){
           if(arr[i][0]<end){
              ans++; 
               // [[1,2],[1,3]]
               // we remove the [1,3] as per the Q 
                   // so keeping the minimum
              end=min(arr[i][1],end);
           }
           else{
             end=arr[i][1];
           }
           i++;
       }
       return ans;
    }
};