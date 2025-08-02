class Solution {
public:
    int giveProfit(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if(ind == prices.size())    return 0;

        if(dp[ind][buy] != -1)  return dp[ind][buy];

        int profit = 0;
        if(buy) { //if buy=1, means can buy
            //there are two cases: 
            // (bought, means money spent & can buy set to can't buy), 
            // (didn't buy, no money spent & still can buy)
            profit = max(-prices[ind] + giveProfit(ind+1, 0, prices, dp), 0 + giveProfit(ind+1, 1, prices, dp));
        } else { //if buy=0, means can't buy, hence can sell
            //there are two cases:
            //(sold, earns profit and set can buy=1, since sold and now can buy again)
            //(didn't sell, no profit and still can't buy, hence buy=0)
            profit = max(prices[ind] + giveProfit(ind+1, 1, prices, dp), 0 + giveProfit(ind+1, 0, prices, dp));
        }
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1)); //2 as buy has two states buy and sell(can't buy)
        return giveProfit(0, 1, prices, dp);
    }
};