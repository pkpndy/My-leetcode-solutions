class Solution {
public:
    //recursive memoised solution
    int comb(int n, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if(n==0) {
            if(amount % coins[0] == 0)   return 1;
            else return 0;
        }

        if(dp[n][amount] != -1)     return dp[n][amount];

        int notTake = comb(n-1, amount, coins, dp);
        int take = 0;
        if(coins[n] <= amount)   take = comb(n, amount-coins[n], coins, dp);

        return dp[n][amount] = notTake+take;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return comb(n-1, amount, coins, dp);
    }

    //tabulated solution
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned int>> dp(n, vector<unsigned int> (amount+1, 0));
        
        for(int i=0; i<=amount; i++) {
            if(i % coins[0] == 0 )  dp[0][i] = 1;
            else dp[0][i] = 0;
        }

        for(int i=1; i<n; i++) {
            for(int j=0; j<=amount; j++) {
                unsigned int notTake = dp[i-1][j];
                unsigned int take = 0;
                if(coins[i] <= j)   take = dp[i][j-coins[i]];

                dp[i][j] = notTake+take;
            }
        }

        return (int)dp[n-1][amount];
    }

    //space optimised
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned int> prev(amount+1, 0);
        
        for(int i=0; i<=amount; i++) {
            if(i % coins[0] == 0 )  prev[i] = 1;
            else prev[i] = 0;
        }

        for(int i=1; i<n; i++) {
            vector<unsigned int> curr(amount+1, 0);
            for(int j=0; j<=amount; j++) {
                unsigned int notTake = prev[j];
                unsigned int take = 0;
                if(coins[i] <= j)   take = curr[j-coins[i]];

                curr[j] = notTake+take;
            }
            prev = curr;
        }

        return (int)prev[amount];
    }
};