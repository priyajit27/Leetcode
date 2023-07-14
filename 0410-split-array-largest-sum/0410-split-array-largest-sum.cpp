class Solution {
public:
    bool isPossible(vector<int> &a,int mid,int m){
    int allocatestudent=1;
    int pages=0;

    for(int i=0;i<a.size();i++){
        if(a[i]>mid)
        return false;
        if(pages+a[i]>mid){
            pages=a[i];
            allocatestudent+=1;
              if(allocatestudent>m)
            return false;
        }
        else
        pages+=a[i];
    }

    //    if(allocatestudent>m)
    //    return false;
       return true;
}
    int splitArray(vector<int>& a, int k) {
         // same Q allocation book
        int n=a.size();
         if(k>n)
	return -1;
	int low=a[0];int high=0;
	for(int i=0;i<n;i++){
		low=min(low,a[i]);
		high+=a[i];
	}
      int ans=0;
	while(low<=high){
       int mid=(high+low)/2;
       if(isPossible(a,mid,k)){
           ans=mid;
           high=mid-1;
       }
       else
       low=mid+1;
	}
	return ans;
    }
};