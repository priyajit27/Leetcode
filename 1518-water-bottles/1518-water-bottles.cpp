class Solution {
public:
    int numWaterBottles(int a, int b) {
        // return a+a/b+1;
        int total=a;
        int empty=a;
        while(empty>=b){
            int full=empty/b;
            total+=full;
            empty=full+ empty%b;
        }
        return total;
    }
};