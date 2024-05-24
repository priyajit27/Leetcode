class Solution {
public:
    int searchInsert(vector<int>& arr, int x) {
//         lower bound
        int n=arr.size();
        int low=0;
	int high=n-1;
     int ans=n;
     int mid;
	 while(low<=high){
          mid=(high+low)/2;
		  if(arr[mid]>=x){
			  ans=mid;
			  high=mid-1;
		  }
		  else
		  low=mid+1;
	 }

	return ans;
    }
};