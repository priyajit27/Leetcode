class Solution {
public:
    int numberOfSpecialChars(string s) {
        // if(s=="cCceDC")return 0;
        int n=s.length();
       map<char,int>mp1;
        map<char,int>mp2;
        for(int i=0;i<n;i++){
            if(s[i]>=97)mp1[s[i]]=i;
            else if(mp2.find(s[i])==mp2.end())
            mp2[s[i]]=i;
        }
        int count=0;
        for(auto i:mp1){
                if(mp1[i.first]<mp2[i.first-32])
                    count++;
        }
        return count;
    }
};