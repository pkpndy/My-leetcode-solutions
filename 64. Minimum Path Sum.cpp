class Solution {
public:
    //recursive memoized solution TC:O(mXn)  SC:O(mXn) + O(m+n)
    int minSum(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(m==0 && n==0)    return grid[m][n]; //if we reach the start we can return this value
        
        //if we go out of bounds then return some really high value,
        //so that it doesn't affect the min value
        if(m<0 || n<0)  return 1e9;
        
        //we are using 1e9 because adding something to INT_MAX gives overflow error
        // INT_MAX = 2,147,483,647
        // 1e9     = 1,000,000,000

        if(dp[m][n] != -1)  return dp[m][n];

        int up = grid[m][n] + minSum(m-1, n, grid, dp); //add the current value and go up
        int left = grid[m][n] + minSum(m, n-1, grid, dp); //add the current value and go left

        return dp[m][n] = min(up, left); //store the result and return min of both the paths
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int> (n, -1));

        return minSum(m-1, n-1, grid, dp);
    }

    /*
    //tabulated solution TC:O(mxn) SC:O(mXn)
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int> (n, -1));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 && j==0)    dp[i][j] = grid[i][j]; //base case will give the value at 0,0
                else if (i==0)  dp[i][j] = grid[i][j] + dp[i][j-1]; //if its the first row
                else if (j==0)  dp[i][j] = grid[i][j] + dp[i-1][j]; //if its the first column
                else {
                    int up = grid[i][j] + dp[i-1][j]; //add the up value
                    int left = grid[i][j] + dp[i][j-1]; //add the left value
                    dp[i][j] = min(up, left); //take the minimum sum
                }
            }
        }
        return dp[m-1][n-1]; //the result gets stored at the end
    }
    */

    /*
    //space optimized solution TC:O(mxn) SC:O(1)
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, 0);
        
        for(int i=0; i<m; i++) {
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++) {
                if(i==0 && j==0)    curr[j] = grid[i][j]; //base case will give the value at 0,0
                else if (i==0)  curr[j] = grid[i][j] + curr[j-1]; //if its the first row
                else if (j==0)  curr[j] = grid[i][j] + prev[j]; //if its the first column
                else {
                    int up = grid[i][j] + prev[j]; //add the up value
                    int left = grid[i][j] + curr[j-1]; //add the left value
                    curr[j] = min(up, left); //take the minimum sum
                }
            }
            prev = curr;
        }
        return prev[n-1]; //the result gets stored at the end of 
    }
    */
};