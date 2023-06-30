//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
		vector<string> AllPossibleStrings(string word){
		  int n=word.length();
		  vector<string>ans;
		  for(int num=0;num<(1<<n );num++){
		      string s="";
		      for(int j=0;j<n;j++){
		          if(num & (1<<j))
		          s+=word[j];
		      }
		      if(s.length()>0)
		      ans.push_back(s);
		  }
		  sort(ans.begin(),ans.end());
		  return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends