class Solution {
public:
    //recursive memoized solution
    int giveLCS(int n, int m, string& word1, string& word2, vector<vector<int>>& dp) {
        if(n<0 || m<0)  return 0;

        if(dp[n][m] != -1)  return dp[n][m];

        if(word1[n] == word2[m]) {
            return dp[n][m] = 1 + giveLCS(n-1, m-1, word1, word2, dp);
        }

        return dp[n][m] = 0 + max(giveLCS(n-1, m, word1, word2, dp), giveLCS(n, m-1, word1, word2, dp));
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        int lcs = giveLCS(n-1, m-1, word1, word2, dp);
        return (n+m) - (2*lcs);
    }

    //tabulated solution
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int j=0; j<=m; j++) dp[0][j] = 0;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else    dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        int lcs = dp[n][m];
        return (n+m) - (2*lcs);
    }

    //space optimised solution
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> prev(m+1, 0);

        // for(int j=0; j<=m; j++) prev[j] = 0; this will be handled by initializing by 0

        for(int i=1; i<=n; i++) {
            vector<int> curr(m+1, 0);
            for(int j=1; j<=m; j++) {
                if(word1[i-1] == word2[j-1]) {
                    curr[j] = 1 + prev[j-1];
                }
                else    curr[j] = 0 + max(prev[j], curr[j-1]);
            }
            prev = curr;
        }

        int lcs = prev[m];
        return (n+m) - (2*lcs);
    }
};