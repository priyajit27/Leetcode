//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        map<int,int>mp;
        int n=fruits.size();
       int i=0,j=0;
       int ans=0;
       while(j<n){
           mp[fruits[j]]++;
           while(mp.size()>2){
            if(mp[fruits[i]]==1){
               mp.erase(fruits[i]);
           }
           else{
           mp[fruits[i]]--;
           }
           i++;
           }
           ans=max(j-i+1,ans);
           j++;
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends