class Solution {
public:
    string reversePrefix(string word, char ch) {
        int j=-1;
        int n=word.length();
        for(int i=0;i<word.length();i++){
            if(word[i]==ch)
            {j=i;break;}
        }
        cout<<j;
        // if(j=-1)return word;
        // 
        reverse(word.begin(),word.begin()+j+1);
        return word;
    }
};