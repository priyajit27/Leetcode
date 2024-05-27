class Solution {
public:
    int m=1e9+7;
    long long power(long long x,long long y){
        if(y==0)
            return 1;
        
        long long ans=power(x,y/2);
        
        ans=(ans*ans)%m;
        
        if(y%2)
            ans=(ans*x)%m;

        return ans;
    }
    int countGoodNumbers(long long n) {
        long long even=n/2+n%2;
        long long odd=n/2;
        return power(5,even)*power(4,odd)%m;
    }
};