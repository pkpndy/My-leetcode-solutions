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


// In this solution we are using this observation
// in tabulation solution of {subset with target sum} dp[index][target]
// each cell gives that the current target is achievable by adding 
// the current index {to make a subset} or not

int subsetSum(int target, vector<int>& arr, vector<vector<int>>& dp) {
    for(int j=0; j<arr.size(); j++) {
        //target 0 is always achievable by not taking anything in the subset
        dp[j][0] = true;
    }
    //at the first index, the number itself is an achievable target by taking it
    if(arr[0]<= target)    dp[0][arr[0]] = true;

    //we start after first row as we have marked whatever is achievable by the 0th index
    for(int i=1; i<arr.size(); i++) {
        //j will represent each number till the target
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
    //we take the total sum of all the elements
    int target = accumulate(arr.begin(), arr.end(), 0);
    //+1 because we want to mark the exact number also, since indexing is 0 based
    vector<vector<int>> dp(n, vector<int> (target+1, 0));
	subsetSum(target, arr, dp); //this is for generating or dp array

    int minDiff = 1e9;
    for(int i=0; i<=(target/2); i++) { //after half the results repeat in opposite order
        //in the last row we have all the numbers that are achievable from 0 to target
        if(dp[n-1][i] == true) {
        int subset2Sum = target - i; //since subset1sum + subset2sum = target
        int diff = abs(subset2Sum-i); //calculating absolute bcoz any one can be greater
        minDiff = min(minDiff, diff); //calculating the minimum difference
        }
    }

    return minDiff;
}

