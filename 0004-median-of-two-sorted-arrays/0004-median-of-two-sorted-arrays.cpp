class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n=nums1.size();
    int m=nums2.size();
    if(m<n) return findMedianSortedArrays(nums2,nums1);
    
    int low=0,high=n;
    while(low<=high){
        int c1=(high+low)/2;
        int c2=(n+m+1)/2-c1;
        
        int left1=c1==0?INT_MIN:nums1[c1-1];
        int left2=c2==0?INT_MIN:nums2[c2-1];
        
        int right1=c1==n?INT_MAX:nums1[c1];
        int right2=c2==m?INT_MAX:nums2[c2];
        
        if(left1<=right2 && left2<=right1){
            if((n+m)%2==0){
                return (max(left1,left2)+min(right1,right2))/2.0;
            }else{
                return max(left1,left2);
            }
        }else if(left1>right2){
            high=c1-1;
        }else{
            low=c1+1;
        }
    }
    return 0.0;
    }
};