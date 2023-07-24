class Solution {
public:
    double myPow(double x, int n) {
           double ans=1.0;
       long long m=n;
        
//         if n is negative
       if(m<0)
       m=m*(-1);
        
        
       while(m){
          if(m%2==0){
             x=x*x;
             m/=2;
          }
          else{
              ans=ans*x;
              m--;
          }
       }
        
        // for negative n
       if(n<0)
       ans=1.0/ans;
      return ans;
    }
};