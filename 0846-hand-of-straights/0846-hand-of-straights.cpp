class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        int n=hand.size();
        if(n%k)
            return false;
        sort(hand.begin(),hand.end());
        map<int,int>mp;
        for(auto i:hand)
            mp[i]++;
        for(int i=0;i<n;i++){
            if(mp[hand[i]]==0)continue;
            
            mp[hand[i]]--;
            for(int j=1;j<k;j++){
                if(mp[hand[i]+j]==0)return false;
                mp[hand[i]+j]--;
            }
        }
        return true;
    }
};