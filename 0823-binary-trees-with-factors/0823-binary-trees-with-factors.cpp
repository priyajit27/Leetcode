#define ll long long
#define mod 1000000007
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<ll,ll>mp;
        sort(arr.begin(),arr.end());
    int ans=0;
        for(auto num:arr){
            ll count=1;
            for(auto it:mp ){
                if(num%it.first==0 && mp.count(num/it.first)==1)
                    count+=(mp[num/it.first]*mp[it.first]);
            }
            mp[num]=count;
            ans=(ans+count)%mod;
        }
        return ans;
    }
};