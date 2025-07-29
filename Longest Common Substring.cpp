/*
You have been given two strings “str1” and “str2”. You have to find the length of the longest common substring.
A string “s1” is a substring of another string “s2” if “s2” contains the same characters as in “s1”, in the same order and in continuous fashion also.

For example :
If “str1” = “abcjklp” and “str2” = “acjkp”  then the output will be 3.

Explanation : The longest common substring is “cjk” which is of length 3.
*/

int giveLCStr(int n, int m, string& str1, string& str2, vector<vector<int>>& dp) {
    int maxLen = 0;

    for(int i=0; i<=n; i++) dp[i][0] = 0;
    for(int j=0; j<=m; j++) dp[0][j] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(str1[i-1] == str2[j-1]) { //if the characters are matching then
                //add 1 to previous diagonal max,
                //which will tell the common subtring length till now
                dp[i][j] = 1 + dp[i-1][j-1];
                maxLen = max(maxLen, dp[i][j]);
            }
            else    dp[i][j] = 0; //if chars don't match set 0
        }
    }

    return maxLen;
}

/*
      ""  a  c  j  k  p
""     0  0  0  0  0  0
a      0  1  0  0  0  0
b      0  0  0  0  0  0
c      0  0  1  0  0  0
j      0  0  0  2  0  0
k      0  0  0  0  3  0
l      0  0  0  0  0  0
p      0  0  0  0  0  1
*/

int LCSubStr(string &str1, string &str2)
{   //Use the tabulated solution of LCSequence with modifications for substring
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    return giveLCStr(n, m, str1, str2, dp);
}