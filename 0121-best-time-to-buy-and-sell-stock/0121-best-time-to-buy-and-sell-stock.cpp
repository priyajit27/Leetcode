class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=INT_MIN;
        int cost=prices[0];
        if(prices.size()==1)return 0;
        
        for(int i=1;i<prices.size();i++){
            cost=min(cost,prices[i]);
            int m=prices[i]-cost;
            profit=max(profit,m);
        }
        return profit;
    }
};