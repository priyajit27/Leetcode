class Solution {
public:
    int mySqrt(int x) {
        long long start=0;
        long long end=x;
        int ans=1;
        long long mid;
        while(start<=end){
          mid=(start+end)/2;
          if(mid*mid==x)
              return mid;
          else if(mid*mid>x)
             end=mid-1;
             else
             start=mid+1;
        }
        return start-1;
    }
};