class Solution {
public:
    int giveLCS(int n, int m, string& str1, string& str2, vector<vector<int>>& dp) {
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int j=0; j<=m; j++) dp[0][j] = 0;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(str1[i-1] == str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
    }

/*
      ""  c  a  b
""    0  0  0  0
a     0  0  1  1
b     0  0  1  2
a     0  0  1  2
c     0  1  1  2
*/

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        giveLCS(n, m, str1, str2, dp);

        string result = "";

        int i=n, j=m;
        while(i>0 && j>0) {
            if(str1[i-1] == str2[j-1]) {
                result = result + str1[i-1];
                i--; j--;
            } else {
                if(dp[i-1][j] >= dp[i][j-1]) {
                    result = result + str1[i-1];
                    i--;
                } else {
                    result = result + str2[j-1];
                    j--;
                }
            }
        }

        while(i>0) {
            result = result + str1[i-1];
            i--;
        }
        while(j>0) {
            result = result + str2[j-1];
            j--;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};