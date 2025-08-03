class Solution {
public:
    //recursive memoized solution
    int giveProfit(int ind, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if(cap==0)  return 0;
        if(ind==prices.size())  return 0;

        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        int profit=0;
        if(buy) {
            profit = max(-prices[ind]+giveProfit(ind+1, 0, cap, prices, dp), 0+giveProfit(ind+1, 1, cap, prices, dp));
        } else {
            profit = max(prices[ind]+giveProfit(ind+1, 1, cap-1, prices, dp), 0+giveProfit(ind+1, 0, cap, prices, dp));
        }

        return dp[ind][buy][cap] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (k+1, -1)));//to access k, we need k+1 size
        return giveProfit(0, 1, k, prices, dp);
    }

    //tabulated solution
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1, 0)));//to access k,we need k+1 size
        // if(cap==0)  return 0;
        // if(ind==prices.size())  return 0;
        
        //initializing with zero does the job of the base cases

        int profit=0;
        for(int ind=n-1; ind>=0; ind--) {
            for(int buy=0; buy<=1; buy++) {
                for(int cap=1; cap<=k; cap++) {
                    if(buy) {
                        profit = max(-prices[ind] + dp[ind+1][0][cap], 0 + dp[ind+1][1][cap]);
                    } else {
                        profit = max(prices[ind] + dp[ind+1][1][cap-1], 0 + dp[ind+1][0][cap]);
                    }
                    dp[ind][buy][cap] = profit;
                }
            }
        }

        return dp[0][1][k];
    }

    //space optimised
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> next(2, vector<int> (k+1, 0));//to access k,we need k+1 size

        int profit=0;
        for(int ind=n-1; ind>=0; ind--) {
            vector<vector<int>> curr(2, vector<int> (k+1, 0));
            for(int buy=0; buy<=1; buy++) {
                for(int cap=1; cap<=k; cap++) {
                    if(buy) {
                        profit = max(-prices[ind] + next[0][cap], 0 + next[1][cap]);
                    } else {
                        profit = max(prices[ind] + next[1][cap-1], 0 + next[0][cap]);
                    }
                    curr[buy][cap] = profit;
                }
            }
            next = curr;
        }

        return next[1][k];
    }
};