class Solution {
public:
    int minCostClimbingStairs(int n, vector<int>& cost, vector<int>& dp) {
        //the cost after 0th or the 1st stair will be 0 
        //as from there we can jump outside directly
        if(n == 0 || n==1)  return 0;

        //check if answer has already been calculated once, if yes then return it
        if(dp[n] != -1) return dp[n];

        int left = minCostClimbingStairs(n-1, cost, dp) + cost[n-1];
        int right = minCostClimbingStairs(n-2, cost, dp) + cost[n-2];
        
        dp[n] = min(left, right); //store the minimum cost from either tree, left or right 
        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, -1);
        return minCostClimbingStairs(cost.size(), cost, dp);
        
        /*
        //This solution is without using stack space, only using dp array
        int minCostClimbingStairs(vector<int>& cost) {
            int n = cost.size();

            if(n==0)    return 0;
            if(n==1)    return 0;

            vector<int> dp(n+1);
            dp[0] = 0;
            dp[1] = 0;

            for(int i=2; i<=n; i++) {
                dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
            }

            return dp[n];
        }
        */
};