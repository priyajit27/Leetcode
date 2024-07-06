class Solution {
public:
    int passThePillow(int n, int time) {
        int x=time/(n-1);
        int y=time%(n-1);
       if(x%2){
           return n-y;
       }
        else
            return y+1;
    }
};