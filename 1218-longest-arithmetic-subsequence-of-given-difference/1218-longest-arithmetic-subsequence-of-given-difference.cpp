class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        map<int,int>mp;
        int maxm=0;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=1+mp[arr[i]-d];
            maxm=max(maxm, mp[arr[i]]);
        }
        return maxm;
    }
};