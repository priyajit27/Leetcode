class Solution {
public:
    int integerReplacement(int nn) {
        int count=0;
        long n=nn;
        while(n>1){
           if(n%2==0)n/=2;
            else if((n+1)%4==0 && (n+1)!=4)
                n++;
            else
                n--;
            count++;
        }
        return count;
    }
};