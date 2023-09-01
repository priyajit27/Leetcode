class Solution {
public:
    int xorOperation(int n, int start) {
        int xr=0;
        for(int i=start;i<2*n+start;i+=2){
            cout<<i;
            xr^=i;
        }
        return xr;
    }
};