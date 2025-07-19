#include <bits/stdc++.h> 

//recursive solution TC:O(2^n) SC:O(n)
bool subsetSumToK(int n, int k, vector<int> &arr) {
    if(k == 0)  return true; //if at any point target is completed return true
    if(n == 0)  return arr[0]==k; //if at the 0th index target is completed return true

    bool notTake = subsetSumToK(n-1, k, arr); //continue without taking the current element
    bool take = false; //in case we were not able to take the element, then target not complete hence false
    if(k>=arr[n]) { //if the current element is smaller or equal to target
        take = subsetSumToK(n-1, k-arr[n], arr); //take the current element and go ahead
    }

    return take || notTake; //return if we got true by taking or not taking
}


///////////memoized solution TC:O(n X k) SC:O(n X k)
bool f(int i, int target, vector<int>& arr, vector<vector<int>>& dp) {

    if(target == 0)  return true;
    if(i == 0)  return arr[0]==target;

    if(dp[i][target] != -1)  return dp[i][target]; //if we already have the result of this index and target

    bool notTake = f(i-1, target, arr, dp);
    bool take = false;
    if(target>=arr[i]) {
        take = f(i-1, target-arr[i], arr, dp);
    }

    return dp[i][target] = take || notTake; //set the result of this index and target and return
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    //dp table is made according to the states that change
    vector<vector<int>> dp(n, vector<int> (k+1, -1)); //here index and target change
    return f(n-1, k, arr, dp);
}


///////////tabulated solution
#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int> (k+1, 0)); //here index and target change

    for(int i=0; i<n; i++) {
        // Base case: target 0 is always achievable (empty subset)
        dp[i][0] = true; //dp[index][target]
    }

    // Base case: first element
    if(arr[0] <= k){  //check if the 0th element is not greater than the target
        //if its greater than it will result in out of bounds
        dp[0][arr[0]]=true;
    }

    for(int i=1; i<n; i++) {
        for(int target=1; target<=k; target++) {
            bool notTake = dp[i-1][target];
            bool take = false;
            if(target >= arr[i]) take = dp[i-1][target-arr[i]];
            dp[i][target] = take || notTake;
        }

    }

    return dp[n-1][k];
}