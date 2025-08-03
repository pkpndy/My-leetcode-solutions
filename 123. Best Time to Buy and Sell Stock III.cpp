class Solution {
public:
    //recursive memoized solution
    int giveProfit(int ind, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if(cap==0)  return 0; //if max number of transaction completed
        if(ind==prices.size())  return 0; //if the prices array is crossed we can't sell anything to get profit

        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        int profit = 0;
        if(buy) {
            profit = max(-prices[ind]+giveProfit(ind+1, 0, cap, prices, dp), 0+giveProfit(ind+1, 1, cap, prices, dp));
        } else { //if wee buy and sell once that means we completed a transaction, hence cap-1
            profit = max(prices[ind]+giveProfit(ind+1, 1, cap-1, prices, dp), 0+giveProfit(ind+1, 0, cap, prices, dp));
        }
        return dp[ind][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        return giveProfit(0, 1, 2, prices, dp); //(index, can buy, max transaction capacity, prices, dp)
    }

    //tabulated solution
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));

        //though wee have written these base cases we dont actually need them 
        //as we already have initialised everything with 0

        // //for cap=0, index and buy can be anything they will be 0 => if(cap==0)  return 0;
        // for(int i=n; i>=0; i--) { //indexes
        //     for(int j=0; j<=1; j++) { //buy states
        //         dp[i][j][0] = 0;  //dp[ind][buy][cap]
        //     }
        // }
        
        // //for index=n, cap and buy can be anything they will be 0 => if(ind==prices.size())  return 0;
        // for(int i=0; i<=2; i++) {
        //     for(int j=0; j<=1; j++) {
        //         dp[n][j][i] = 0;  //dp[ind][buy][cap]
        //     }
        // }

        int profit = 0;
        for(int ind=n-1; ind>=0; ind--) { //since for index=n we already filled
            for(int buy=0; buy<=1; buy++) {
                for(int cap=1; cap<=2; cap++) { //since for cap=0 we already filled
                    if(buy) {
                        profit = max(-prices[ind] + dp[ind+1][0][cap], 0 + dp[ind+1][1][cap]);
                    } else {
                        profit = max(prices[ind] + dp[ind+1][1][cap-1], 0 + dp[ind+1][0][cap]);
                    }
                    dp[ind][buy][cap] = profit;
                }
            }
        }

        return dp[0][1][2]; //[0] coz index = n to 0 ,[1] coz buy = 0 to 1, [2] coz cap = 0 to 2; 
    }

    //space optimized solution
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> next(2, vector<int> (3, 0));

        //no base cases coz we already have initialised everything with 0

        int profit = 0;
        for(int ind=n-1; ind>=0; ind--) { //since for index=n we already filled
        vector<vector<int>> curr(2, vector<int> (3, 0));
            for(int buy=0; buy<=1; buy++) {
                for(int cap=1; cap<=2; cap++) { //since for cap=0 we already filled
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

        return next[1][2];
    }
};