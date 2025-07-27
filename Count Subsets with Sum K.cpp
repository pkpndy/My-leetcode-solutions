/*
You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'.

Find the number of ways of selecting the elements from the array such that the sum of chosen elements is equal to the target 'k'.

Since the number of ways can be very large, print it modulo 10 ^ 9 + 7.

Example:
Input: 'arr' = [1, 1, 4, 5]

Output: 3

Explanation: The possible ways are:
[1, 4]
[1, 4]
[5]
Hence the output will be 3. Please note that both 1 present in 'arr' are treated differently.
*/

const int MOD = 1e9 + 7;

//this is memoized recursive solution but it wont work for large test cases, use tabulation
int subsetSumK(int ind, vector<int>& arr, int k, vector<vector<int>>& dp) {
	// If no elements left (ind == 0):
	if (ind == 0) {
		// Only arr[0] left:
		if (k == 0 && arr[0] == 0) return 2; // two ways: pick or not pick 0
		if (k == 0 || arr[0] == k) return 1; // one way: pick nothing or pick only this
		return 0;
	}

	if(dp[ind][k] != -1)	return dp[ind][k];

	int notTake = subsetSumK(ind-1, arr, k, dp);
	int take = 0;
	if(arr[ind] <= k) {
		take = subsetSumK(ind-1, arr, k-arr[ind], dp);
	}
	return dp[ind][k] = (take + notTake) % MOD;
}


int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int> (k+1, -1));
	return subsetSumK(n-1, arr, k, dp);
}


//tabulation solution
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int> (k+1, 0));
	if(arr[0] == 0) {
        dp[0][0] = 2;  // Two ways: take 0 or don't take 0 (both give sum=0)
    } else {
        dp[0][0] = 1;  // One way: don't take first element
        if(arr[0] <= k) 
            dp[0][arr[0]] = 1;  // One way: take first element
    }
	
	for(int i=1; i<arr.size(); i++) {
		for(int j=0; j<=k; j++) {
			int notTake = dp[i-1][j];
			int take = 0;
			if(arr[i] <= j) {
				take = dp[i-1][j-arr[i]];
			}
			dp[i][j] = (take + notTake)% MOD;
		}
	}

	return dp[n-1][k];
}

//space optimised
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<int> prev(k+1, 0);
	if(arr[0] == 0) {
        prev[0] = 2;  // Two ways: take 0 or don't take 0 (both give sum=0)
    } else {
        prev[0] = 1;  // One way: don't take first element
        if(arr[0] <= k) 
            prev[arr[0]] = 1;  // One way: take first element
    }
	
	for(int i=1; i<arr.size(); i++) {
		vector<int> curr(k+1, 0);
		for(int j=0; j<=k; j++) {
			int notTake = prev[j];
			int take = 0;
			if(arr[i] <= j) {
				take = prev[j-arr[i]];
			}
			curr[j] = (take + notTake)% MOD;
		}
		prev = curr;
	}

	return prev[k];
}