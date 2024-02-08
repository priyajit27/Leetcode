class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789";
         vector<int>ans;
        for(int i=0;i<s.size();i++){
            string str="";
            for(int j=i;j<s.size();j++){
                str+=s[j];
                int a=stoi(str);
                if(low<=a && a<=high){
                    ans.push_back(a);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};