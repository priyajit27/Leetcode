class Solution {
public:
    int rec(int num){
        int ans;
        int n=num;
        int rem=0;
        while(n){
            rem+=n%10;
            n/=10;
        }
        if(rem>9)
            ans=rec(rem);
        else 
            ans=rem;
        return ans;
    }
    int addDigits(int num) {
        return rec(num);
    }
};