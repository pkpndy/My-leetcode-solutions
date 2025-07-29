/*
Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. 
Determine the maximum cost obtained by cutting the rod and selling its pieces.

Note:
1. The sizes will range from 1 to ‘N’ and will be integers.

2. The sum of the pieces cut should be equal to ‘N’.

3. Consider 1-based indexing.

Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= A[i] <= 100

Where ‘T’ is the total number of test cases, ‘N’ denotes the length of the rod, and A[i] is the cost of sub-length.

Time limit: 1 sec.
Sample Input 1:
2
5
2 5 7 8 10
8
3 5 8 9 10 17 17 20
Sample Output 1:
12
24
Explanation of sample input 1:
Test case 1:

All possible partitions are:
1,1,1,1,1           max_cost=(2+2+2+2+2)=10
1,1,1,2             max_cost=(2+2+2+5)=11
1,1,3               max_cost=(2+2+7)=11
1,4                 max_cost=(2+8)=10
5                   max_cost=(10)=10
2,3                 max_cost=(5+7)=12
1,2,2               max _cost=(1+5+5)=12    

Clearly, if we cut the rod into lengths 1,2,2, or 2,3, we get the maximum cost which is 12.
*/


//recursive memoized solution
int maxCost(int n, vector<int>& price, int target, vector<vector<int>>& dp) {
    //the question is saying consider 1-based indexing
    //as rod cut size can't be 0 but prices vector is 0-based
	if (n == 0) {
        // Only pieces of size 1 available, use as many as fit
        return target * price[0];
    }

	if(dp[n][target] != -1)	return dp[n][target];

	int notTake = 0 + maxCost(n-1, price, target, dp);
	int take = 0;
	if(n+1 <= target) {
		take = price[n] + maxCost(n, price, target-(n+1), dp);
	}

	return dp[n][target] = max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
	return maxCost(n-1, price, n, dp);
}

//tabulated solution
int maxCost(int n, vector<int>& price, int target, vector<vector<int>>& dp) {
	//the question is saying consider 1-based indexing
	//as size can't be 0 but prices vector is 0-based
	for(int i=0; i<=target; i++) {
		dp[0][i] = i*price[0];
	}

	for(int i=1; i<n; i++) {
		for(int j=0; j<=target; j++) {
			int notTake = 0 + dp[i-1][j];
			int take = 0;
			if(i+1 <= j) {
				take = price[i] + dp[i][j-(i+1)];
			}

			dp[i][j] = max(take, notTake);
		}
	}

	return dp[n-1][n];
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n, vector<int> (n+1, 0));
	return maxCost(n, price, n, dp);
}


//space optimised solution
int cutRod(vector<int> &price, int n)
{
	vector<int> prev(n+1, 0);
	int target = n;
	for(int i=0; i<=target; i++) {
		prev[i] = i*price[0];
	}

	for(int i=1; i<n; i++) {
		vector<int> curr(n+1, 0);
		for(int j=0; j<=target; j++) {
			int notTake = 0 + prev[j];
			int take = 0;
			if(i+1 <= j) {
				take = price[i] + curr[j-(i+1)];
			}

			curr[j] = max(take, notTake);
		}
		prev = curr;
	}

	return prev[n];
}

