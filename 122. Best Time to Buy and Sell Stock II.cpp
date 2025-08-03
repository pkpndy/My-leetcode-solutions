class Solution {
public:
    int giveProfit(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if(ind == prices.size())    return 0; //if the prices array is crossed we can't sell anything to get profit

        if(dp[ind][buy] != -1)  return dp[ind][buy];

        int profit = 0;
        if(buy) { //if buy=1, means can buy
            //there are two cases: 
            // (bought, means money spent & can buy set to can't buy), {choose}
            // (didn't buy, no money spent & still can buy) {not choose}
            profit = max(-prices[ind] + giveProfit(ind+1, 0, prices, dp), 0 + giveProfit(ind+1, 1, prices, dp));
        } else { //if buy=0, means can't buy, hence can sell
            //there are two cases:
            //(sold, earns profit and set can buy=1, since sold and now can buy again) {choose}
            //(didn't sell, no profit and still can't buy, hence buy=0) {not choose}
            profit = max(prices[ind] + giveProfit(ind+1, 1, prices, dp), 0 + giveProfit(ind+1, 0, prices, dp));
        }
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1)); //2 as buy has two states buy and sell(can't buy)
        return giveProfit(0, 1, prices, dp); //(starting index, can buy, prices, dp)
    }

    //tabulated solution
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //since base case had ind==n, so to accomodate n we increase the size of dp vector
        vector<vector<int>> dp(n+1, vector<int> (2, 0));
        // if(ind == n)    return 0;
        dp[n][0] = dp[n][1] = 0; //set the n=0, according to the base case

        // if(dp[ind][buy] != -1)  return dp[ind][buy];

        int profit = 0;
        for(int ind=n-1; ind>=0; ind--) { //ind=n-1->0
            for(int buy=0; buy<=1; buy++) { //buy=0->1 (for can buy and can't buy)
                if(buy) { //can buy
                    profit = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]); //max(buy, not buy)
                } else { //can't buy, hence sell
                    profit = max(prices[ind] + dp[ind+1][1], 0 + dp[ind+1][0]); //max(sell, not sell)
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }

    //space optimization
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> next(2, 0);
        next[0] = next[1] = 0;

        int profit = 0;
        for(int ind=n-1; ind>=0; ind--) {
        vector<int> curr(2, 0);
            for(int buy=0; buy<=1; buy++) {
                if(buy) {
                    profit = max(-prices[ind] + next[0], 0 + next[1]);
                } else {
                    profit = max(prices[ind] + next[1], 0 + next[0]);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
};