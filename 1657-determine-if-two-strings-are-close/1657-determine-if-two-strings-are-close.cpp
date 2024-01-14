class Solution {
public:
    bool closeStrings(string word1, string word2) {
        set<char>s1;
        set<char>s2;
        vector<int>a(26,0);
        vector<int>b(26,0);
        for(auto i:word1)
            s1.insert(i);
         for(auto i:word2)
            s2.insert(i);
        for(auto i:word1){
            a[i-'a']++;
        }
          for(auto i:word2){
            b[i-'a']++;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a==b && s1==s2)return true;
        return false;
    }
};