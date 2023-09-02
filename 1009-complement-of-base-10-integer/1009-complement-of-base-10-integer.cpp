class Solution {
public:
    int bitwiseComplement(int n) {
       vector<int>num;
        if(n==0)return 1;
        while(n){
            num.push_back(n%2);
            n/=2;
        }
        for(int i=0;i<num.size();i++){
            if(num[i]==1)num[i]=0;
             else if(num[i]==0)num[i]=1;               
        }
        int res=0;
         for(int i=num.size()-1;i>=0;i--){
          res=2*res+num[i];  
        }
        return res;
    }
};