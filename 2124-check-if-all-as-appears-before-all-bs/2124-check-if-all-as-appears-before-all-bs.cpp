class Solution {
public:
    bool checkString(string s) {
       string a=s;
        sort(s.begin(),s.end());
        if(s==a)
            return true;
        return false;
    }
};