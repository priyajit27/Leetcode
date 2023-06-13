class Solution {
public:
    int first(vector<int> &arr, int x, int n){
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
    int last(vector<int> &arr, int x, int n){
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
    vector<int> searchRange(vector<int>& arr,int x) {
        int n=arr.size();
        int f=first(arr,x,n);
        int l=last(arr,x,n);
        
         vector<int>ans;
        ans.push_back(f);
         ans.push_back(l);
        return ans;
    }
};