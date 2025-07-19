class Solution {
public:
    //recursive solution, but this won't work bcoz of too many recursive calls
    //TC:O(3^n) because its making 3 calls at every position SC:O(N) recursion stack space
    
    //memoised solution will take TC:O(nXm) {but this also won't work bcoz of too many recursive calls} SC:O(nXm) + O(n)
    int minPath(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        int n = mat.size();
        int m = mat[0].size();

        if(i>=n || j<0 || j>=m) return 1e9; //always add check for out of bounds condition first
        if(i == n-1) {
            return mat[i][j];
        }

        if(dp[i][j] != -1)  return dp[i][j];

        int lDia = mat[i][j] + minPath(i+1, j-1, mat, dp); 
        int down = mat[i][j] + minPath(i+1, j, mat, dp); 
        int rDia = mat[i][j] + minPath(i+1, j+1, mat, dp);

        return dp[i][j] = min(lDia, min(down, rDia)); 
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size(), 0));

        for(int a=0; a<matrix[0].size(); a++) {
            mini = min(mini, minPath(0, a, matrix, dp));
        }
        return mini;
    }

    /*
    //tabulated solution
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int> (m, 0));
        for(int i=0; i<matrix[0].size(); i++) {
            dp[0][i] = matrix[0][i];
        }

        for(int x=1; x<n; x++) {
            for(int y=0; y<m; y++) {
                int lDia=1e9, down=1e9, rDia=1e9;
                if(y>0) lDia = matrix[x][y] + dp[x-1][y-1];
                down = matrix[x][y] + dp[x-1][y];
                if(y<m-1) rDia = matrix[x][y] + dp[x-1][y+1];
                dp[x][y] = min(lDia, min(down, rDia));
            }
        }

        int dmin = 1e9;
        for(int a=0; a<m; a++) {
            dmin = min(dmin, dp[n-1][a]);
        }
        return dmin;
    }

    //space optimised solution 
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> dp(m);
        for(int i=0; i<matrix[0].size(); i++) {
            dp[i] = matrix[0][i];
        }

        for(int x=1; x<n; x++) {
            vector<int> curr(m, 0);
            for(int y=0; y<m; y++) {
                int lDia=1e9, down=1e9, rDia=1e9;
                if(y>0) lDia = matrix[x][y] + dp[y-1];
                down = matrix[x][y] + dp[y];
                if(y<m-1) rDia = matrix[x][y] + dp[y+1];
                curr[y] = min(lDia, min(down, rDia));
            }
            dp = curr;
        }

        return *min_element(dp.begin(), dp.end());
    }
    */
};