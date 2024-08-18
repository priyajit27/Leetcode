class Solution {
public:
    int nthUglyNumber(int n) {
       vector<int>aa(n+1);
        int a=1;
        int b=1;
        int c=1;
        aa[1]=1;
        for(int i=2;i<=n;i++){
            int l1=aa[a]*2;
            int l2=aa[b]*3;
            int l3=aa[c]*5;
            int minm=min(l1,min(l2,l3));
            aa[i]=minm;
            if(aa[i]==l1)a++;
             if(aa[i]==l2)b++;
             if(aa[i]==l3)c++;
        }
        return aa[n];
    }
};