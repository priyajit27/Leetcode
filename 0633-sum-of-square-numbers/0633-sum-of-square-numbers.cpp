class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i=0;
        long long j=sqrt(c);
        while(i<=j){
            // int b=sqrt(j);
          long long d=i*i+j*j;
            if(d==c)
                return true;
            if(d>c)
                j--;
            else
                i++;
        }
        return false;
    }
};