class Solution {
public:
    int countSeniors(vector<string>& details) {
        // 
        int ans=0;
        for(int i=0;i<details.size();i++){
            string s=details[i];
            string s1="";
            s1+=s[11];
            s1+= s[12];
            cout<<s1<<"";
            int x;
            x=stoi(s1);
            if(x>60)
                ans++;
        }
        return ans;
    }
};