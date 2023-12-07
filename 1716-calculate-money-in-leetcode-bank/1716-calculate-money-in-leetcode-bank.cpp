class Solution {
public:
    int totalMoney(int n) {
        int week=1;
        int ans=0;
        int day=1;
        for(int i=1;i<=n;i++){
            ans+=day;
            day++;
            if(i%7==0){
                day=week+1;
                week++;
            }
        }
        return ans;
    }
};