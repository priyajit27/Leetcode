class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        int count=0;
      // Pattern 1: "010101..."
        // Pattern 2: "101010..."
        int count1=0;
        int count2=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
//        Pattern 1         
                if(s[i]!='0')count1++;
                // Pattern 2
                 if(s[i]!='1')count2++;
            }
            else{
               //        Pattern 1         
                if(s[i]!='1')count1++;
                // Pattern 2
                 if(s[i]!='0')count2++; 
            }
        }
        return min(count1,count2);
    }
};