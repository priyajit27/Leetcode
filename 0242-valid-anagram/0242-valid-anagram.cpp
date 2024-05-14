class Solution {
public:
    bool isAnagram(string s, string t) {
          unordered_map<char,int>m1;
         unordered_map<char,int>m2;
         for(auto i:s)
         m1[i]++;
         for(auto i:t){
              m1[i]--;
             if(m1[i]==0)
                 m1.erase(i);
         }
        if(m1.empty())
        return true;
        return false;
    }
};