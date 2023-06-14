//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	// If ans can be in point decimal places

// #include <bits/stdc++.h>
// using namespace std;
// double multiply(double number, int n) {
//     double ans = 1.0;
//     for(int i = 1;i<=n;i++) {
//         ans = ans * number;
//     }
//     return ans; 
// }

// void getNthRoot(int n, int m) {
//     double low = 1;
//     double high = m;
//     double eps = 1e-7; 
    
//     while((high - low) > eps) {
//         double mid = (low + high) / 2.0; 
//         if(multiply(mid, n) < m) {
//             low = mid; 
//         }
//         else {
//             high = mid; 
//         }
//     }
//     cout <<n<<"th root of "<<m<<" is "<<low<<endl; 
// }



	int NthRoot(int n, int m){
	      int low=1;
	     int high=m;
        int mid;
      
	 while(low<=high){
          mid=(high+low)/2;
      // if(multiply(n,mid)==m)
       if(pow(mid,n)==m)
      return mid;
       if(pow(mid,n)<m)
    low=mid+1;
      else
      high=mid-1;
             
	 }
        return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends