class Solution {
public:
    int countPrimes(int n) {
         if(n<=2)
        return 0;
        vector<int>a(n,0);
         for(int i=2;i<a.size();i++){
              a[i]=i;
         }
         a[0]=0;
         a[1]=0;
         for(int i=2;i*i<n;i++){
             if(a[i]!=0){
                 for(int j=i+i;j<n;j+=i){
                     a[j]=0;
                 }
             }
         }
         int count=0;
         for(auto i:a){
             if(i!=0)
             count++;
         }
        return count;
        
      
    }
};