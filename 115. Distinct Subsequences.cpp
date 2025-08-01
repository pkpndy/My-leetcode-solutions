class Solution {
public:
    int giveDS(int n, int m, string& s, string& t, vector<vector<int>>& dp) {
        //if we found match of all the characters of string t and reached below 0
        if(m<0) return 1;
        //if we reached below 0 and since we checked for crossing 0 in t already
        //and reaching here means the a char in t is still waiting for a match
        //but we crossed all chars in s, hence return 0
        if(n<0) return 0;

        if(dp[n][m] != -1)  return dp[n][m];

        if(s[n] == t[m]) { //if matched
            int take = giveDS(n-1,m-1, s, t, dp); //we can take the character in s
            int notTake = giveDS(n-1, m, s, t, dp); //we can not take this and take the next matching character
            return dp[n][m] = take + notTake;
        } else {
            return dp[n][m] = giveDS(n-1, m, s, t, dp); //if not matched then move forward
        }
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n, vector<int> (m, -1));

        return giveDS(n-1, m-1, s, t, dp);
    }

    //tabulated solution
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<unsigned int>> dp(n+1, vector<unsigned int> (m+1, 0));

        for(int i=0; i<=n; i++) dp[i][0] = 1;
        //adding for(int j=0; j<=m; j++)    dp[0][j] = 0; gives error
        //because this line sets dp[0][0] = 0; 
        //so dont set 0 for i==0 it is already set during initialization

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i-1] == t[j-1]) { //if matched
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j]; //if not matched then move forward
                }
            }
        }

        return (int)dp[n][m];
    }

    //space optimised solution
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<unsigned int> prev(m+1, 0);

        prev[0] = 1;

        for(int i=1; i<=n; i++) {
            vector<unsigned int> curr(m+1, 0);
            curr[0] = 1; //since each row had first column set to 1
            for(int j=1; j<=m; j++) {
                if(s[i-1] == t[j-1]) { //if matched
                    curr[j] = prev[j-1] + prev[j];
                } else {
                    curr[j] = prev[j]; //if not matched then move forward
                }
            }
            prev = curr;
        }

        return (int)prev[m];
    }
};