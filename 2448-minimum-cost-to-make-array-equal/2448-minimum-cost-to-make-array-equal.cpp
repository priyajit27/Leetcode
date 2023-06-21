class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
          int n = nums.size(), l = 1, r = INT_MAX;
        long long res = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            res = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] <= mid)res += cost[i];
                else res -= cost[i];
            }
            if (res < 0)l = mid + 1;
            else r = mid - 1;
        }
        res = 0;
        for (int i = 0; i < n; ++i)
            res += (long long) abs(nums[i] - l) * cost[i];

        return res;
    }
};