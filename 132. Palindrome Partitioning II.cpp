class Solution {
public:
    bool isPalindrome(int i, int j, string& s) {
        while(i<j) {
            if(s[i++] != s[j--])    return false;
        }
        return true;
    }

    int minPart(int i, string& str, vector<int>& dp) {
        if(i==str.size())   return 0; //if we checked for all the chars as the starting of a range 
        if(dp[i] != -1) return dp[i];
        int mini = INT_MAX;
        for(int j=i; j<str.size(); j++) { //checks for each char if adding it will be a palindromic partition
            if(isPalindrome(i, j, s)) { //if adding the current character made this partition palindromic
                int cost = 1 + minPart(j+1, str, dp); //if yes, then add 1 and start searching after this character
                mini = min(mini, cost);
            }
        }
        return dp[i] = mini;
    }

    int minCut(string s) {
        vector<int> dp(s.size(), -1);
        //we give the starting of the range to check for number of partitions
        return minPart(0, s, dp) - 1; // -1 because we want cuts in between but our partition counts at the end also
    }

    //tabulated solution
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--) {
            int mini = INT_MAX;
            for(int j=i; j<n; j++) {
                if(isPalindrome(i, j, s)) {
                    int cost = 1 + dp[j+1];
                    mini = min(mini, cost);
                }
            }
            dp[i] = mini;
        }
        return dp[0]-1;
    }
};