class Solution {
public:
    int getSum(int a, int b) {
        // return a+b;
        
        while(b){
            int sum=a^b;
            
            int carry=(a&b)<<1;
            
            a=sum;
            b=carry;
        }
        return a;
    }
};