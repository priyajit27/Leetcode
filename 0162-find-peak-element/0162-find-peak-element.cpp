class Solution {
public:
    int findPeakElement(vector<int>& arr) {
          int n=arr.size();
         int low=0;
	    int high=n-1;
        int index=-1;
     // int maxm=INT_MIN;
     int mid;
      if(n==1)
          return 0;
        if(arr[0]>arr[1])
            return 0;
           if(arr[n-1]>arr[n-2])
            return n-1;
        low=1;high=n-2;
	 while(low<=high){
          mid=(high+low)/2;
        
         if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
             return mid;
         
         if(arr[mid]<arr[mid-1])
             high=mid-1;
         else
             low=mid+1;
             
	 }
        return -1; 
    }
};