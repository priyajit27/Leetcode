 int setbit(int n){
        int count=0;
        while(n){
            if((n&1)==1)count++;
            n=n>>1;
        }
        return count;
    }
     bool compare( int i, int j){
        int a=setbit(i);
         int b=setbit(j);
        if(a==b)
            return i<j;
        return a<b;
    }
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};