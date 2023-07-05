//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int check(string& s,int k){
         vector<int>v(26,0);
         int n=s.length();
         if(s.size()==0)
        return 0;
        long long ans=0;
        int left=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(v[s[i]-'a']==0)
            count++;
            v[s[i]-'a']++;
            
        while(count>k){
            v[s[left]-'a']--;
            if(v[s[left]-'a']==0)
            count--;
            left++;
        }
            ans+=i-left+1;
        }
        
        return ans;
  }
    int countSubstring(string s) {
        // Code here
           int k=3;
         return check(s,k)-check(s,k-1);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends