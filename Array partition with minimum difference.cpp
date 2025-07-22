/*
You are given an array 'arr' containing 'n' non-negative integers.

Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.

You just need to find the minimum absolute difference considering any valid division of the array elements.

Note:

1. Each array element should belong to exactly one of the subsets.

2. Subsets need not always be contiguous.
For example, for the array : [1, 2, 3], some of the possible divisions are 
   a) {1,2} and {3}
   b) {1,3} and {2}.

3. Subset-sum is the sum of all the elements in that subset. 
Example:
Input: 'n' = 5, 'arr' = [3, 1, 5, 2, 8].

Ouput: 1

Explanation: We can partition the given array into {3, 1, 5} and {2, 8}. 
This will give us the minimum possible absolute difference i.e. (10 - 9 = 1).

*/

int subsetSum(int target, vector<int>& arr, vector<vector<int>>& dp) {
    for(int j=0; j<arr.size(); j++) {
        dp[j][0] = true;
    }
    if(arr[0]<= target)    dp[0][arr[0]] = true;

    for(int i=1; i<arr.size(); i++) {
        for(int j=1; j<=target; j++) {
            int notTake = dp[i-1][j];
            int take = false;
            if(arr[i]<=j) {
                take = dp[i-1][j-arr[i]];
            }
            dp[i][j] = notTake || take;
        }
    }
    return dp[arr.size()-1][target];
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
    int target = accumulate(arr.begin(), arr.end(), 0);
    vector<vector<int>> dp(n, vector<int> (target+1, 0));
	subsetSum(target, arr, dp);

    int minDiff = 1e9;
    for(int i=0; i<=(target/2); i++) {
        if(dp[n-1][i] == true) {
        int subset2Sum = target - i;
        int diff = abs(subset2Sum-i);
        minDiff = min(minDiff, diff);
        }
    }

    return minDiff;
}
