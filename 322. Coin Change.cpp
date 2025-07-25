class Solution {
public:
    //recursive memoized solution
    int minCoins(int n, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if(n==0) {//if last element reached
            //if taking this coin repeatedly will make the target amount left then
            if(amount % coins[0] == 0)  return (amount/coins[0]); //return the number of coins required
            else return 1e9; //else return any hgih number as this will make the result really high
        }

        if(dp[n][amount] != -1) return dp[n][amount];

        int notTake = 0 + minCoins(n-1, amount, coins, dp); //if not taken the coin
        int take = INT_MAX;
        //take this coin decrease the amount left
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

    //tabulated solution
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));

        //we can only take the coin->coins[i] if the amount is divisible by coin 
        for(int i=0; i<=amount; i++) {
            if(i%coins[0] == 0) dp[0][i] = i/coins[0];
            else dp[0][i] = 1e9; //else return some high number
        }

        for(int i=1; i<n; i++) {
            for(int j=0; j<=amount; j++) {
                int notTake = 0 + dp[i-1][j];
                int take = 1e9;
                if(coins[i] <= j) {
                    take = 1 + dp[i][j-coins[i]];
                }

                dp[i][j] = min(take, notTake);
            }
        }
        
        int res = dp[n-1][amount];
        if(res >= 1e9)  return -1;
        return res;
    }

    //space optimised solution
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1, 0);

        for(int i=0; i<=amount; i++) {
            if(i%coins[0] == 0) prev[i] = i/coins[0];
            else prev[i] = 1e9;
        }

        for(int i=1; i<n; i++) {
            vector<int> curr(amount+1, 0);
            for(int j=0; j<=amount; j++) {
                int notTake = 0 + prev[j];
                int take = 1e9;
                if(coins[i] <= j) {
                    take = 1 + curr[j-coins[i]];
                }
                curr[j] = min(take, notTake);
            }
            prev = curr;
        }

        int res = prev[amount];
        if(res >= 1e9)  return -1;
        return res;
    }
};