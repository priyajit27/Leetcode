//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   bool compare(string &a ,string &b){
        if(a.size()!=b.size()+1)
            return false;
        int i=0;
        int j=0;
        while(i<a.size()){
            if(j<b.size() && a[i]==b[j]){
                i++;
                j++;
            }
            else 
                i++;
        }
        if(i==a.size() && j==b.size())
            return true;
        return false;
    }
    static bool comp(string &a,string &b){
        return a.size()<b.size();
    }
    int longestChain(int n, vector<string>& words) {
        //  int n=words.size();
        sort(words.begin(),words.end(),comp);
         int maxi=1;
        vector<int>dp(n+1,1);
        for(int ind=0;ind<n;ind++){
            for(int prev=0;prev<ind;prev++){
                if( compare(words[ind],words[prev]) && dp[ind]<1+ dp[prev] ){
                    dp[ind]=1+ dp[prev];
                }
            }
            maxi=max(maxi,dp[ind]);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends