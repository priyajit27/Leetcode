class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        // NlogN solution
       // for(int i=0;i<n;i++){
       //     nums1[i+m]=nums2[i];
       // }
       //  sort(nums1.begin(),nums1.end());
        
        
        // N+M
        
        int i=n-1;
        int j=m-1;
        int k=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                k--;i--;
            }
            else{
                 nums1[k]=nums2[j];
            k--;
            j--;
            }
        }
       
        while(j>=0){
            nums1[k]=nums2[j];
            k--;
            j--;
        }
          while(i>=0){
            nums1[k]=nums1[i];
            k--;
            i--;
        }
    }
};