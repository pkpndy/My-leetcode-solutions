class Solution {
public:
    int minPath(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        int n = mat.size();
        int m = mat[0].size();

        for(int x=1; x<n; x++) {
            for(int y=0; y<m; y++) {
                int lDia=1e9, down=1e9, rDia=1e9;
                if(y>0) lDia = mat[i][j] + dp[i-1][j-1];
                down = mat[i][j] + dp[i-1][j];
                if(y<m-1) rDia = mat[i][j] + dp[i-1][j+1];
                dp[i][j] = min(lDia, min(down, rDia));
            }
        }

        int dmin = 1e9;
        for(int a=0; a<m; a++) {
            dmin = min(dmin, dp[n-1][a]);
        }
        return dmin;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size(), 0));

        for(int a=0; a<matrix[0].size(); a++) {
            mini = min(mini, minPath(0, a, matrix, dp));
        }
        return mini;
    }
};