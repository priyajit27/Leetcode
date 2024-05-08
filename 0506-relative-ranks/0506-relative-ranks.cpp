class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string>ans;
        vector<int>a;
        a=score;
        sort(a.begin(),a.end(),greater<int>());
        map<int,string>mp;
        for(int i=0;i<a.size();i++){
             if(i>2)
                mp[a[i]] = to_string(i+1);
            else if(i==0)
                  mp[a[i]] = "Gold Medal";
               else if(i==1)
                  mp[a[i]] = "Silver Medal";
               else if(i==2)
                  mp[a[i]] = "Bronze Medal";
        }
        for(int i=0;i<score.size();i++){
            ans.push_back(mp[score[i]]);
        }
        
        return ans;
    }
};