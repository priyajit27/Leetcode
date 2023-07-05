//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string s, int k) {
        //         O(N)         Sc almost O(1) as the array is 26 size only
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

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends