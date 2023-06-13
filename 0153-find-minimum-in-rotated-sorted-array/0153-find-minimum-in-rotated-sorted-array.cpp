class Solution {
public:
    int findMin(vector<int>& arr) {
             int n=arr.size();
        int low=0;
	    int high=n-1;
     int minm=INT_MAX;
     int mid;
      
	 while(low<=high){
          mid=(high+low)/2;
		  if(arr[mid]>=arr[low]){
			 minm=min(minm,arr[low]);
               low=mid+1;
              // high=mid-1;
		  }
         else{
              minm=min(minm,arr[mid]);
              // low=mid+1;
                high=mid-1;
         }
             
	 }
        return minm;
    }
};