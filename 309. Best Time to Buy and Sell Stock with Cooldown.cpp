class Solution {
public:
    int getPro(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if(ind>=prices.size())  return 0;

        if(dp[ind][buy] != -1)  return dp[ind][buy];

        int profit = 0;
        if(buy) {
            profit = max(-prices[ind] + getPro(ind+1, 0, prices, dp), 0 + getPro(ind+1, 1, prices, dp));
        } else { //after selling we can't buy next day hence day after next day ind+2
            profit = max(prices[ind] + getPro(ind+2, 1, prices, dp), 0 + getPro(ind+1, 0, prices, dp));
        }

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return getPro(0, 1, prices, dp);
    }

    //tabulated solution
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int> (2, 0)); //since ind+2 will give overflow error
        // if(ind>=prices.size())  return 0;

        int profit = 0;
        for(int ind=n-1; ind>=0; ind--) {
            for(int buy=0; buy<=1; buy++) {
                if(buy) {
                    profit = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
                } else { //after selling we can't buy next day hence day after next day ind+2
                    profit = max(prices[ind] + dp[ind+2][1], 0 + dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }

    //space optimized
    nt maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> next2(2, 0);
        vector<int> next1(2, 0);

        int profit = 0;
        for(int ind=n-1; ind>=0; ind--) {
            vector<int> curr(2, 0);
            for(int buy=0; buy<=1; buy++) {
                if(buy) {
                    profit = max(-prices[ind] + next1[0], 0 + next1[1]);
                } else { //after selling we can't buy next day hence day after next day ind+2
                    profit = max(prices[ind] + next2[1], 0 + next1[0]);
                }
                curr[buy] = profit;
            }
            next2=next1;
            next1=curr;
        }
        return next1[1];
    }
};