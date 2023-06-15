class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            int start=arr[i][0];
            int end=arr[i][1];
            
            if(ans.size() && end<=ans[ans.size()-1][1])
                continue;
            
            
            for(int j=i+1;j<n;j++){
                  if(arr[j][0]<=end){
                      end=max(arr[j][1],end);
                  }
                else
                    break;
            }
            ans.push_back({start,end});
            // ans.push_back(end);
        }
        return ans;
    }
};