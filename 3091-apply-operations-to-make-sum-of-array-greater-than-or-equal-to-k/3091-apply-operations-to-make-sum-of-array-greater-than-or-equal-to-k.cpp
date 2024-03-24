class Solution {
public:
    int minOperations(int k) {
        int m=ceil(sqrt(k));
        return m+(k-1)/m-1;
    }
};