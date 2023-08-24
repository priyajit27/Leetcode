class Solution {
public:
    bool canConstruct(string s1, string s2) {
       map<char,int>mp1,mp2;
        for(auto i:s1)
            mp1[i]++;
        
          for(auto i:s2)
            mp2[i]++;
        
        for(auto i:mp1){
            if(mp1[i.first]>mp2[i.first])
                return false;
        }
        return true;
    }
};