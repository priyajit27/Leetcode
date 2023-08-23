class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int l=left;
        int r=right;
      if(left==0 || right==0)
          return 0;
        
       int count1=0,count2=0;
        while(left){
            count1++;
            left=left>>1;
        }
          while(right){
            count2++;
            right=right>>1;
        }
        
        if(count1!=count2)return 0;
        
        long long res=l;
        for(long long int i=l;i<=r;i++){
            res &=i;
            // if(left==0)
            //     return 0;
        }
        return res;
    }
};