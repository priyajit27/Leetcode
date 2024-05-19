class Solution {
public:
    int characterReplacement(string s, int k) {
         vector<int>cnt(26,0);
        int left = 0, right = 0;
        int count = 0;
        int ans= 0;
        
        while(right<s.length()){
            cnt[s[right]-'A']++;
            count=max(count, cnt[s[right]-'A']);
            while(right-left+1-count>k){
                 cnt[s[left]-'A']--;
                 left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};