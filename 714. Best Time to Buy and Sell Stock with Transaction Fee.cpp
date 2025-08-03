class Solution {
public:
    int gp(int ind, int buy, int fee, vector<int>& prices, vector<vector<int>>& dp) {
        if(ind==prices.size())  return 0;

        if(dp[ind][buy] != -1)  return dp[ind][buy];

        int profit = 0;
        if(buy) {
            profit = max(-prices[ind]+gp(ind+1, 0, fee, prices, dp), 0+gp(ind+1, 1, fee, prices, dp));
        } else {
            profit = max((prices[ind]+gp(ind+1, 1, fee, prices, dp))-fee, 0+gp(ind+1, 0, fee, prices, dp));
        }

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return gp(0, 1, fee, prices, dp);
    }
};