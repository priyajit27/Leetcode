class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
    vector<string> ans;
      vector<int>min_freq(26,INT_MAX);
    for (int i=0; i<words.size(); i++) {
        vector<int>freq(26,0);
        for(auto j:words[i])
            freq[j-'a']++;
        for(int k=0;k<26;k++){
            min_freq[k]=min(min_freq[k],freq[k]);
        }
    }
        for(int i=0;i<26;i++){
            while(min_freq[i]--){
                ans.push_back(string(1,i+'a'));
            }
        }    
    return ans; 
    }
};