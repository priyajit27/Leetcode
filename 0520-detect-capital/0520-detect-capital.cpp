class Solution {
public:
    bool detectCapitalUse(string s) {
        int count1=0;
         int count2=0;
        int n=s.length();
        int c1=0;
        int c2=0;
        if(isupper(s[0]))c1++;
        for (int i=0;i<n;i++){
           if(isupper(s[i]))
             count1++;
            if(islower(s[i]))
             count2++;
        }
         for (int i=1;i<n;i++){
        
            if(islower(s[i]))
             c2++;
        }
       if(count1==n)return true;
       if(count2==n)return true; 
        if(c1==1 && c2==n-1)
            return true;
        return false;

    }
};