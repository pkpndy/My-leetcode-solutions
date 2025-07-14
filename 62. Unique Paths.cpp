class Solution {
public:
    // this memoized recursive solution takes 
    // TC: O(n X m) SC: O(n + m) {path length} + O(n X m) {stack space} 
    int countPaths(int m, int n, vector<vector<int>>& dp) {
        // In this recursive solution we go from top to bottom n->0
        //hence we are going from the ending to starting point
        if(m == 0 && n == 0)    return 1; //if we reach 0 that means it is a valid solution
        if(m<0 || n<0)  return 0; //if we go out of bounds that means we took a wrong step

        if(dp[m][n] != -1)  return dp[m][n]; //if result has already been computed

        int up = countPaths(m-1, n, dp); // take step upwards
        int left = countPaths(m, n-1, dp); // take step left

        return dp[m][n] = up + left; //store the result and return
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1)); //dp array to memoize
        return countPaths(m-1, n-1, dp);
    }

    /*
    // this tabulated solution takes 
    // TC: O(n X m) SC: O(n X m) {because of for loop} 
    int countPaths(int m, int n, vector<vector<int>>& dp) {
        for(int i=0; i<m; i++) {
            int up=0, left=0;
            for(int j=0; j<n; j++) {
                if(i==0 && j==0)    dp[0][0] = 1; //we start with 1 because its a path
                else {
                    if(i>0) up = dp[i-1][j]; //cheking i>0 so that we don't reach -ve index
                    if(j>0) left = dp[i][j-1]; //cheking j>0 so that we don't reach -ve index
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1)); //dp array to memoize
        return countPaths(m, n, dp); //sending m, n because we are gonna exclude them in loop
    }   
    */

    /*
    // this space optimised solution takes TC: O(n X m) SC: O(1) 
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0); //dp array to store previous row (for up direction values)
        for(int i=0; i<m; i++) {
            vector<int> curr(n, 0); //each time we create and fill entire row by using j
            int up=0, left=0;
            for(int j=0; j<n; j++) {
                if(i==0 && j==0)    curr[j] = 1; // we start with 1 because its a path
                else {
                    if(i>0) up = dp[j]; //cheking i>0 so that we don't reach -ve index
                    if(j>0) left = curr[j-1]; //cheking j>0 so that we don't reach -ve index
                    curr[j] = up + left;
                }
            }
            dp = curr;
        }
        return dp[n-1]; //the final answer gets stored in the end of the dp array
    }
    */

};