class Solution {
public:
    int myAtoi(string s) {
          int n=s.length();
      if(s.length()==0)
          return 0;
        
        int i=0;
        while(i<n && s[i]==' '){
            i++;
        }
        
        int sign=+1;
        long ans=0;
        
        if(s[i]=='+' ){
            i++;
        }
        else if(s[i]=='-'){
            i++;
            sign=-1;
        }
        
        int maxm=INT_MAX;
        int minm=INT_MIN;
        
        while(i<s.length() && isdigit(s[i])){
            ans=ans*10+s[i]-'0';
//             here if we take int ans then it will overflow here so we have taken long
            if(ans*sign>=maxm)
                return maxm;
            if(ans*sign<=INT_MIN)
                return minm;
            i++;
        }
    
        return sign*ans;
    }
};