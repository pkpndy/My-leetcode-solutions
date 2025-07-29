class Solution {
public:
    //recursive memoized solution
    int giveLCS(int i, int j, string& text1, string& text2, vector<vector<int>>& dp) {
        //here i and j means substring of s1[0 to i] and s2[0 to j]

        //if either of the indexes become negative max length returned from there is 0
        if(i<0 || j<0)    return 0;

        if(dp[i][j] != -1)    return dp[i][j];

        if(text1[i] == text2[j]) { //if indexes match add 1 to the length returned and move indexes to the left
            return dp[i][j] = 1 + giveLCS(i-1, j-1, text1, text2, dp);
        }

        //if the indexes don't match get the max by moving i to the left and then j to the left 
        return dp[i][j] = 0 + max(giveLCS(i-1, j, text1, text2, dp), giveLCS(i, j-1, text1, text2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return giveLCS(n-1, m-1, text1, text2, dp);
    }

    //right shifting index by 1 recursive memoized solution (useful for tabulation later)
    int giveLCS(int i, int j, string& text1, string& text2, vector<vector<int>>& dp) {
        //here i and j means substring of s1[0 to i] and s2[0 to j]

        if(i==0 || j==0)    return 0; //instead of <0 now we start from ==0

        if(dp[i][j] != -1)    return dp[i][j];

        if(text1[i-1] == text2[j-1]) { //since the actual values will be at -1 position as we right shifted i+1 
            return dp[i][j] = 1 + giveLCS(i-1, j-1, text1, text2, dp);
        }

        return dp[i][j] = 0 + max(giveLCS(i-1, j, text1, text2, dp), giveLCS(i, j-1, text1, text2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1)); //+1 because we are shifting 1 to the right
        return giveLCS(n, m, text1, text2, dp); //sending n and m as the last index
    }

    //tabulated solution
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1)); //+1 because we are shifting 1 to the right
        
        //here i and j means substring of s1[0 to i] and s2[0 to j]
        for(int i=0; i<=n; i++)  dp[i][0] = 0; //we were returning 0 if j==0
        for(int j=0; j<=m; j++)  dp[0][j] = 0; //we were returning 0 if i==0

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(text1[i-1] == text2[j-1]) { //since the actual values will be at -1 position as we right shifted i+1 
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else    dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }

    //space optimised solution
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m+1, 0); //+1 because we are shifting 1 to the right
        
        //here i and j means substring of s1[0 to i] and s2[0 to j]
        for(int j=0; j<=m; j++)  prev[j] = 0; //we were returning 0 if i==0

        for(int i=1; i<=n; i++) {
            vector<int> curr(m+1, 0);
            for(int j=1; j<=m; j++) {
                if(text1[i-1] == text2[j-1])    curr[j] = 1 + prev[j-1];
                else    curr[j] = 0 + max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[m];
    }
};