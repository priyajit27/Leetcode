/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peak_index(MountainArray &mountainArr){
        int low=0;
        int high=mountainArr.length()-1;
                 while(low<high){
        int mid=low+(high-low)/2;
        if(mountainArr.get(mid)<mountainArr.get(mid+1))
            low=mid+1;
        else
            high=mid;
                 }
        return low;
    }
     int left_part(int low,int high,int target,MountainArray &mountainArr){
         while(low<=high){
             int mid=low+(high-low)/2;
              if(mountainArr.get(mid)==target)
            return mid;
        else if(mountainArr.get(mid)<target)
            low=mid+1;
        else high=mid-1;
         }
         return -1;
    }
    int right_part(int low,int high,int target,MountainArray &mountainArr){
           while(low<=high){
               int mid=low+(high-low)/2;
        if(mountainArr.get(mid)==target)
            return mid;
        else if(mountainArr.get(mid)>target)
            low=mid+1;
        else high=mid-1;
           }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak=peak_index(mountainArr);
        cout<<peak;
        int left=left_part(0,peak,target,mountainArr);
            if(left!=-1)
                return left;
        int right=right_part(peak,mountainArr.length()-1,target,mountainArr);
            if(right!=-1)return right;
        return -1;
    }
};