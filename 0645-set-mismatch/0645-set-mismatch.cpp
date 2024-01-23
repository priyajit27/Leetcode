class Solution {
public:
    vector<int> findErrorNums(vector<int>& a) {
           //S-Sn  x-y
    //S2-Sn2  x2-y2
  long long n=a.size();
    long long S=(n*(n+1))/2;
      long long S2=(n*(n+1)*(2*n+1))/6;
        long long sum=0,sum2=0;
        for(int i=0;i<n;i++){
              sum+=a[i];
        sum2+=(long long)a[i]*(long long)a[i];
        }
        long long val1=sum-S;
        long long val2=sum2-S2;
        val2=val2/val1;
        long long x=(val1+val2)/2;
        long long y =x-val1;
        return {(int)(x),(int)(y)};
    }
};