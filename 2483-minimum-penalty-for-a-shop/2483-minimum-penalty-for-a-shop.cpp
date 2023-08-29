class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.length();
        int penalty=0;
        int min_penalty=0;
        int min_hr=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y')
                penalty++;
        }
        
        min_penalty=penalty;
        
           for(int i=1;i<=n;i++){
            if(customers[i-1]=='Y'){
                penalty--;
            }
               else
                   penalty++;
               
               if(min_penalty>penalty){
                  min_penalty=penalty ;
                   min_hr=i;
               }
        }
        
        
        return min_hr;
    }
};