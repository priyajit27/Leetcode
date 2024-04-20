class Solution {
public:
    bool isHappy(int n) {
        while(n!=1 && n!=4){
            int x=0;
            while(n>0){
                int y=n%10;
                x+=y*y;
                n/=10;
            }
            n=x;
        }
        return n==1;
    }
};