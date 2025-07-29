/*
You are given two strings ‘s1’ and ‘s2’.

Return the longest common subsequence of these strings.

If there’s no such string, return an empty string. If there are multiple possible answers, return any such string.

Note:
Longest common subsequence of string ‘s1’ and ‘s2’ is the longest subsequence of ‘s1’ that is also a subsequence of ‘s2’. 
A ‘subsequence’ of ‘s1’ is a string that can be formed by deleting one or more (possibly zero) characters from ‘s1’.

Example:
Input: ‘s1’  = “abcab”, ‘s2’ = “cbab”

Output: “bab”

Explanation:
“bab” is one valid longest subsequence present in both strings ‘s1’ , ‘s2’.
*/



int giveLCS(int n, int m, string& s1, string& s2, vector<vector<int>>& dp) {

	for(int i=0; i<=n; i++)	dp[i][0] = 0;
	for(int j=0; j<=m; j++)	dp[0][j] = 0;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(s1[i-1] == s2[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else	dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
		}
	}

	return dp[n][m];
}

/*
    ""  b  d  g  e  k
""   0  0  0  0  0  0
a    0  0  0  0  0  0
b    0  1  1  1  1  1
c    0  1  1  1  1  1
d    0  1  2  2  2  2
e    0  1  2  2  3  3
*/

string findLCS(int n, int m,string &s1, string &s2){
	//here we are gonna use the table from the tabulated solution of LCS
	vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
	giveLCS(n, m, s1, s2, dp);

	string res;

	int i=n, j=m;
	while(i>0 && j>0) { //if any of them reaches 0 stop
		if(s1[i-1] == s2[j-1]) { //if both characters are equal and -1 is needed because of the right shift
			res = s1[i-1] + res; //add the character to the result string
			i--; j--; //move up-left diagonally
		} else {
			if(dp[i-1][j] > dp[i][j-1]) { //if up is greater than left
				i--; //move up
			} else { //if left is greater than up
				j--; //move left
			}
		}
	}
	return res;
}
