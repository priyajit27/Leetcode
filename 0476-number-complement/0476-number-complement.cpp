class Solution {
public:
    int findComplement(int num) {
        long long int number=num;
        long long  int count=0;
        while(num){
            count++;
            num=num>>1;
        }
        // cout<<count;
        long long  int n=1<<count;
       // cout<<n;
        n=n-1;
        return n^number;
    }
};