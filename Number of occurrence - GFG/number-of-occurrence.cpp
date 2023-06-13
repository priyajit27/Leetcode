//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
		   int first(int arr[], int x, int n){
	int low=0;
	int high=n-1;
     int ans=-1;
     int mid;
	 while(low<=high){
          mid=(high+low)/2;
		  if(arr[mid]==x){
			  ans=mid;
			  high=mid-1;
		  }
		  else if(arr[mid]<x)
		  low=mid+1;
         else
             high=mid-1; 
	 }

	return ans;
}
    int last(int arr[], int x, int n){
	int low=0;
	int high=n-1;
     int ans=-1;
     int mid;
	 while(low<=high){
          mid=(high+low)/2;
		  if(arr[mid]==x){
			  ans=mid;
			    low=mid+1;
		  }
		  else if(arr[mid]<x)
		  low=mid+1;
         else
                high=mid-1; 
	 }

	return ans;
}
    
	int count(int arr[], int n, int x) {
	       //int n=arr.size();
        int f=first(arr,x,n);
        int l=last(arr,x,n);
        
        if(f==-1)
        return 0;
        return l-f+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends