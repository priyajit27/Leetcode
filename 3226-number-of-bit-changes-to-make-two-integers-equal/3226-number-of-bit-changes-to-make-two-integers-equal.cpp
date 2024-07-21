class Solution {
public:
    int minChanges(int n, int k) {
        int count=0;
        while(n>0){
            int x=n&1;
            cout<<x<<" ";
            int y=k&1;
             cout<<y<<" ";
           if(x==1 && y==0)count++;
          else if(x==0 && y==1)
            return -1;
            n=n>>1;
            k=k>>1;
        }
        if(k>0)return -1;
        return count;
    }
};