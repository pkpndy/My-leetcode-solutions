class Solution {
public:
    int minCoins(int n, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if(n==0) {
            if(amount % coins[0] == 0)  return (amount/coins[0]);
            else return 1e9;
        }

        if(dp[n][amount] != -1) return dp[n][amount];

        int notTake = 0 + minCoins(n-1, amount, coins, dp);
        int take = INT_MAX;
        if(coins[n] <= amount)  take = 1 + minCoins(n, amount-coins[n], coins, dp);

        return dp[n][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));

        int res = minCoins(n-1, amount, coins, dp);
        if(res == 1e9)  return -1;
        else return res;
    }
};