class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char>s;
        int count=0;
        for(auto i:word)s.insert(i);
        for(auto i:s){
            if(s.find(i+32)!=s.end())
                count++;
        }
        return count;
    }
};