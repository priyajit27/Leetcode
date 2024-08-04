class Solution {
public:
    int m=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // int n=nums.size();
        vector<int>a;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                a.push_back(sum);
            }
        }
        // for(auto i:a)
        //     cout<<i<<" ";
        sort(a.begin(),a.end());
        int ans=0;
        for(int i=left-1;i<right;i++){
            ans=(ans+a[i])%m;
        }
        return ans;
    }
};