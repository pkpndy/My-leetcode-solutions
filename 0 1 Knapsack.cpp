#include<vector>

//recursive memoized solution
int giveMax(int n, int* wt, int* val, int cap, vector<vector<int>>& dp) {
	if(n==0) {
		if(wt[n] <= cap)	return val[n];
		else	return 0;
	}

	if(dp[n][cap] != -1)	return dp[n][cap];

	int notTake = 0 + giveMax(n-1, wt, val, cap, dp);
	int take = -1e8;
	if(wt[n] <= cap) {
		take = val[n] + giveMax(n-1, wt, val, cap-wt[n], dp);
	}

	return dp[n][cap] = max(take, notTake);
}

int knapsack(int *weights, int *values, int n, int maxWeight)
{
	vector<vector<int>> dp(n, vector<int> (maxWeight+1, -1));
	return giveMax(n-1, weights, values, maxWeight, dp);
}


//tabulation solution
int knapsack(int *weights, int *values, int n, int maxWeight)
{
	vector<vector<int>> dp(n, vector<int> (maxWeight+1, 0));
	// if(n==0) {
	// 	if(weights[n] <= maxWeight)	return values[n];
	// 	else	return 0;
	// }

	//in the recursion base case we had for i==0, values[0] for
	//all weights below capacity, so we fill the values[0] for them
	//rest all will automatically be 0, as dp was initialised with 0
	for(int i=weights[0]; i<=maxWeight; i++) {
		dp[0][i] = values[0];
	}

	for(int i=1; i<n; i++) {
		for(int j=0; j<=maxWeight; j++) {
			int notTake = 0 + dp[i-1][j];
			int take = -1e8;
			if(weights[i] <= j) {
				take = values[i] + dp[i-1][j-weights[i]];
			}

			dp[i][j] = max(take, notTake);
		}
	}
	return dp[n-1][maxWeight];
}

//space optimised solution
int knapsack(int *weights, int *values, int n, int maxWeight)
{
	vector<int> prev(maxWeight+1, 0);
	for(int i=weights[0]; i<=maxWeight; i++) {
		prev[i] = values[0];
	}

	for(int i=1; i<n; i++) {
		vector<int> curr(maxWeight+1, 0);
		for(int j=0; j<=maxWeight; j++) {
			int notTake = 0 + prev[j];
			int take = -1e8;
			if(weights[i] <= j) {
				take = values[i] + prev[j-weights[i]];
			}

			curr[j] = max(take, notTake);
		}
		prev = curr;
	}
	return prev[maxWeight];
}