class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int x=prices[0]+prices[1];
        if(money-x>=0)
            return money-x;
        else
            return money;
    }
};