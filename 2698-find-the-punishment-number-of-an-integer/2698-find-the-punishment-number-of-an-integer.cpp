class Solution {
public:
    bool check(string s,int target){
        if(s=="" && target==0)
            return true;
        if(target<0)
            return false;
        bool ans =false;
        for(int i=0;i<s.length();i++){
              string left=s.substr(0,i+1);
              string right=s.substr(i+1);
            int leftNum=stoi(left);
            bool partition=check(s.substr(i+1),target-leftNum);
            if(partition){
                ans=true;
                break;
            }
        }
        return ans;
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            int square=i*i;
            if(check(to_string(square),i))
                ans+=square;
        }
        return ans;
    }
};