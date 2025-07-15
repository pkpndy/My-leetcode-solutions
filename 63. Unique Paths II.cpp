class Solution {
public:
    //this is memoized recursive solution TC:O(m X n) SC:O(m+n) + O(n X m)
    int uniquePaths(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        //always check the m<0 or n<0 check at the top or don't check for those
        //out of bounds position as they will give you 
        //runtime error: addition of unsigned offset to 0x508000000020 overflowed
        if(m==0 && n==0)    return grid[0][0] == 0 ? 1:0; //if the starting cell is blocked
        //checking grid[m][n] before n<0 and m<0 will give error
        if(m<0 || n<0 || grid[m][n]==1)    return 0;

        if(dp[m][n] != -1)  return dp[m][n];

        int up = uniquePaths(m-1, n, grid, dp);
        int left = uniquePaths(m, n-1, grid, dp);

        return dp[m][n] = up+left;

    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return uniquePaths(m-1, n-1, obstacleGrid, dp);
    }

    /*
    //this is tabulated solution TC:O(n X m) SC:O(n X m)
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));

        dp[0][0] = obstacleGrid[0][0] == 0 ? 1:0; //if the starting cell is blocked

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 && j==0) continue;  // Skip the starting cell
                //setting 0 as reaching those positions returned 0
                if(obstacleGrid[i][j] == 1) {  // Check if current cell is blocked
                    dp[i][j] = 0;              // Set paths to this cell as 0
                    continue;                  // Skip to next iteration
                }
                int up=0, left=0;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                dp[i][j] = up + left;
                }
        }
        return dp[m-1][n-1];
    }
    */

};