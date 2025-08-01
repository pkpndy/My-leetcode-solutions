class Solution {
public:
    //recursive memoized solution
    int giveED(int n, int m, string& word1, string& word2, vector<vector<int>>& dp) {
        //if word1 is completed then remaining no. of chars of word2 will be added to word1
        //which will be m+1 operations
        if(n<0) return m+1;
        //if word2 is traversed then remaining no. of chars of word1 will be removed from word1
        //which will be n+1 operations
        if(m<0) return n+1;

        if(dp[n][m] != -1)  return dp[n][m];
        
        if(word1[n] != word2[m]) { //if chars don't match
            //when you delete a char in word1 you move left and again check of the same char of word2 
            int del = 1 + giveED(n-1, m, word1, word2, dp);
            //when you replace you placed the exact char in that position so now both match
            int replace = 1 + giveED(n-1, m-1, word1, word2, dp);
            //when you insert the current char of word2 you move left in word2 as 
            //the insertion made the required conversion but the position in word1 remains same bcoz
            // insertion adds the char just after that index
            int insert = 1 + giveED(n, m-1, word1, word2, dp);

            return dp[n][m] = min(del, min(replace, insert)); //take the minimum of all three possibilities
        }
        return dp[n][m] =  0 + giveED(n-1, m-1, word1, word2, dp); //in case the chars match, no operation
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return giveED(n-1, m-1, word1, word2, dp);
    }

    //tabulated solution
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        // if(n<0) return m+1;
        // if(m<0) return n+1;
        for(int j=0; j<=m; j++) dp[0][j] = j; //came from the base cases if i==0 return j+1 for n<0 return m+1
        for(int i=0; i<=n; i++) dp[i][0] = i; //it would have been i+1 but in tabulation i=i-1 hence i

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(word1[i-1] != word2[j-1]) {
                    int del = 1 + dp[i-1][j];
                    int replace = 1 + dp[i-1][j-1];
                    int insert = 1 + dp[i][j-1];
                    dp[i][j] = min(del, min(replace, insert));
                }
                else dp[i][j] =  0 + dp[i-1][j-1];
            }
        }

        return dp[n][m];
    }

    //space optimised
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> prev(m+1, 0);
        for(int j=0; j<=m; j++) prev[j] = j; 

        for(int i=1; i<=n; i++) {
            vector<int> curr(m+1, 0);
            curr[0] = i;
            for(int j=1; j<=m; j++) {
                if(word1[i-1] != word2[j-1]) {
                    int del = 1 + prev[j];
                    int replace = 1 + prev[j-1];
                    int insert = 1 + curr[j-1];
                    curr[j] = min(del, min(replace, insert));
                }
                else curr[j] =  0 + prev[j-1];
            }
            prev = curr;
        }

        return prev[m];
    }
};