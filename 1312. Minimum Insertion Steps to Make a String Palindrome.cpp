class Solution {
public:
/*
We have observed that min number of insertions = string.size() - Longest Palindromic Subsequence
*/

    //recursive memoized solution
    int giveLPS(int n, int m, string& s, string& s2, vector<vector<int>>& dp) {
        if(n<0 || m<0)  return 0;

        if(dp[n][m] != -1)  return dp[n][m];

        if(s[n] == s2[m]) {
            return dp[n][m] = 1 + giveLPS(n-1, m-1, s, s2, dp);
        }

        return dp[n][m] = 0 + max(giveLPS(n-1, m, s, s2, dp), giveLPS(n, m-1, s, s2, dp));
    }

    int minInsertions(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int lps = giveLPS(n-1, n-1, s, s2, dp);
        return n-lps;
    }

    //tabulated solution
    int minInsertions(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        int m = n;

        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int j=0; j<=m; j++) dp[0][j] = 0;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else    dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int lps = dp[n][m];

        return n - lps;
    }

    //space optimised solution
    int minInsertions(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(), s2.end());
        vector<int> prev(n+1, 0);

        // for(int j=0; j<=m; j++) prev[j] = 0; already set 0 during initialization

        for(int i=1; i<=n; i++) {
            vector<int> curr(n+1, 0);
            for(int j=1; j<=n; j++) {
                if(s[i-1] == s2[j-1]) {
                    curr[j] = 1 + prev[j-1];
                }
                else    curr[j] = 0 + max(prev[j], curr[j-1]);
            }
            prev = curr;
        }

        int lps = prev[n];

        return n - lps;
    }
};