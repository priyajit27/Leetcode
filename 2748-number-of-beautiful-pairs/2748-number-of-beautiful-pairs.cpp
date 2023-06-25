class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // int first=nums[i] / pow(10, floor(log10(nums[i])));
                string s=to_string(nums[i]);
                int first=s[0]-'0';
                int last=nums[j]%10;
                
                if(__gcd(first,last)==1)
                    ans++;
            }
        }
        return ans;
    }
};