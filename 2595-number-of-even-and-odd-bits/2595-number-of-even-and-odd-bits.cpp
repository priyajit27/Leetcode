class Solution {
public:
    vector<int> evenOddBit(int n) {
       
        int even=0;
        int odd=0;
        int i=1;
       while(n){
            // n=n>>1;
            int a=n & 1;
           i++;
             if(i%2==0 && a==1)even++;
            else if(i%2==1 && a==1)odd++;
             n=n>>1;
        }
       return {even,odd};
    }
};