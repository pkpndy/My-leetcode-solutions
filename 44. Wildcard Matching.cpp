class Solution {
public:
    //recursive memoized solution
    bool checkMatch(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if(i<0 && j<0) return true; //matched everything in pattern and string
        if(j<0 && i>=0) return false; //pattern exhausted but string is remaining
        if(i<0 && j>=0) { //string exhausted but pattern is remaining
            for(int x=j; x>=0; x--) { //then check if it has something other than stars
                if(p[x] != '*') return false; //if yes then false
            }
            //means everything left in the pattern was star and stars will represent empty sequence
            return true;
        }

        if(dp[i][j] != -1)  return dp[i][j];


        if(s[i] == p[j] || p[j] == '?') { //if the characters match or the char is '?'
            return dp[i][j] = checkMatch(i-1, j-1, s, p, dp); //then both will move to next
        } else if (p[j] == '*') {//if the char is '*'
        //case one the * will be an empty sequence then i(s) will stay at the same place, j(p) will move
        //case two the * will represent one char sequence then i(s) will move, j(p) will stay
            return dp[i][j] = checkMatch(i, j-1, s, p, dp) || checkMatch(i-1, j, s, p, dp);
        }

        return false; //if nothing gave true, then its false
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return checkMatch(n-1 , m-1, s, p, dp);
    }

    //tabulated solution
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));
        dp[0][0] = true;
        for(int x=1; x<=n; x++) dp[x][0] = false;
        // 2. Base Case: Empty string vs. Non-empty pattern
        // This can only be a match if the pattern consists of only '*' characters.

        for (int k = 1; k <= m; k++) {
        // It means: a pattern p of length j that ends in a * can match an empty string if and 
        //only if the pattern of length j-1 (the part without the *) could also match an empty string.
            if (p[k - 1] == '*') {
                dp[0][k] = dp[0][k - 1];
            // The * is essentially matching zero characters, so it contributes nothing, 
            //and we just inherit the answer from the previous, smaller subproblem.
            }
            // Note: If p[j-1] is not '*', dp[0][j] remains false, which is correct.
        }

        for(int a=1; a<=n; a++) {
            for(int b=1; b<=m; b++) {
                if(s[a-1] == p[b-1] || p[b-1] == '?') {
                    dp[a][b] = dp[a-1][b-1];
                } else if (p[b-1] == '*') {
                    dp[a][b] = dp[a][b-1] || dp[a-1][b];
                }
                else dp[a][b] = false;
            }
        }

        return dp[n][m];
    }

    //space optimised solution
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<bool> prev(m+1, false);
        prev[0] = true;

        for (int k = 1; k <= m; k++) {
            if (p[k - 1] == '*') {
                prev[k] = prev[k - 1];
            }
        }

        for(int a=1; a<=n; a++) {
            vector<bool> curr(m+1, false);
            for(int b=1; b<=m; b++) {
                if(s[a-1] == p[b-1] || p[b-1] == '?') {
                    curr[b] = prev[b-1];
                } else if (p[b-1] == '*') {
                    curr[b] = curr[b-1] || prev[b];
                }
                else curr[b] = false;
            }
            prev = curr;
        }

        return prev[m];
    }
};