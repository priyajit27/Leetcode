class Solution {
public:
    int minLength(string s) {
        int n=s.length();
        string ans="";
    int subtract = 0;
    for (int i = 0; i < n; ++i) {
        ans.push_back(s[i]);
        if (ans.size() >= 2) {
            if (ans.substr(ans.size() - 2, 2) == "AB" || ans.substr(ans.size() - 2, 2) == "CD") {
                subtract += 2;
                int  count = 0;
                while (count != 2) {
                    ans.pop_back();
                    ++count;
                }
            }
        }
    }
        return n-subtract;
    }
};