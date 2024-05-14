class Solution {
public:
    string largestOddNumber(string num) {
        // for(int i=num.length()-1;i>=0;i--){
        //     if((int)num[i]%2==0)
        //         num.pop_back();
        //     else
        //         break;
        // }
        // return num; 
        
        string s="";
        int index=-1;
         for(int i=num.length()-1;i>=0;i--){
            if(num[i]%2!=0){
                 index=i;
                break;
            }
        }
         for(int i=0;i<=index;i++){
            s+=num[i];
        }
        return s;
    }
};