/*
Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union is the original array. Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.

Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ and the difference between ‘S1’ and ‘S2’ is equal to ‘D’. Since the answer may be too large, return it modulo ‘10^9 + 7’.

If ‘Pi_Sj’ denotes the Subset ‘j’ for Partition ‘i’. Then, two partitions P1 and P2 are considered different if:

1) P1_S1 != P2_S1 i.e, at least one of the elements of P1_S1 is different from P2_S2.
2) P1_S1 == P2_S2, but the indices set represented by P1_S1 is not equal to the indices set of P2_S2. Here, the indices set of P1_S1 is formed by taking the indices of the elements from which the subset is formed.
Refer to the example below for clarification.
Note that the sum of the elements of an empty subset is 0.

For example :
If N = 4, D = 3, ARR = {5, 2, 5, 1}
There are only two possible partitions of this array.
Partition 1: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
Partition 2: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
These two partitions are different because, in the 1st partition, S1 contains 5 from index 0, and in the 2nd partition, S1 contains 5 from index 2.
*/

#include <bits/stdc++.h> 
const int MOD = 1e9+7;

//recursive memoized solution
int countPart(int n, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if(target==0)   return 1;
    if(n == 0) { //When n == 0, we're at the first element of the array (arr).
    //This is our last decision point - we can either: Take it or Not take it
        
        //taking or not taking the element both will give us the target sum
        if(target == 0 && arr[0] == 0) return 2;
        
        //(target==0) target is achieved then not taking 0th index is a way 
        if(target == 0 || target == arr[0]) return 1;
        //(target==arr[0]) target remaining == arr[0], then taking it is a way

        return 0; //return 0 if we reached first element but target wasn't achieved
    }
    
    if(dp[n][target] != -1) return dp[n][target];

    int notTake = countPart(n-1, target, arr, dp);
    int Take = 0;
    if(arr[n] <= target)    Take = countPart(n-1, target-arr[n], arr, dp);

    return dp[n][target] = (notTake + Take)%MOD;
}

int countPartitions(int n, int d, vector<int> &arr) {
    //since the conditions say S1-S2=D => S1=D+S2 and S1>=S2 and total=S1+S2
    //hence our target is total = D+S2+S2 => S2 = (total-D)/2
    int total = accumulate(arr.begin(), arr.end(), 0);
    int target = (total-d)/2;
    
    //total-d has to be >0, as we are calculating sum of a subset
    //since its a subset of the array doesn't have any -ve values
    if(total-d<0 || (total-d)%2)    return false;
    //total-d has to be even as dividing it by 2 has to be an int not float

    vector<vector<int>> dp(n, vector<int> (target+1, -1));
    return countPart(n-1, target, arr, dp);
}


//tabulated solution
int countPartitions(int n, int d, vector<int> &arr) {
    //since the conditions say S1-S2=D => S1=D+S2 and S1>=S2 and total=S1+S2
    //hence our target is total = D+S2+S2 => S2 = (total-D)/2
    int total = accumulate(arr.begin(), arr.end(), 0);
    int target = (total-d)/2;
    
    //total-d has to be >0, as we are calculating sum of a subset
    //since its a subset of the array doesn't have any -ve values
    if(total-d<0 || (total-d)%2)    return false;
    //total-d has to be even as dividing it by 2 has to be an int not float

    vector<vector<int>> dp(n, vector<int> (target+1, 0));
    if(arr[0] == 0) dp[0][0] = 2; //two ways
    else dp[0][0] = 1; //target is 0 and reached last index, then one way

    //arr[0]!=0 because we might change the previously set dp[0][0]
    if(arr[0] != 0 && arr[0] <= target)    dp[0][arr[0]] = 1;

    for(int i=1; i<arr.size(); i++) {
        for(int tar=0; tar<=target; tar++) {
            int notTake = dp[i-1][tar];
            int Take = 0;
            if(arr[i] <= tar)    Take = dp[i-1][tar-arr[i]];
            dp[i][tar] = (notTake + Take)%MOD;
        }
    }
    return dp[n-1][target];
}

//space optimised solution
int countPartitions(int n, int d, vector<int> &arr) {
    int total = accumulate(arr.begin(), arr.end(), 0);
    int target = (total-d)/2;
    
    if(total-d<0 || (total-d)%2)    return false;

    vector<int> prev(target+1, 0);
    if(arr[0] == 0) prev[0] = 2; //two ways
    else prev[0] = 1; //target is 0 and reached last index, then one way

    if(arr[0] != 0 && arr[0] <= target)    prev[arr[0]] = 1;

    for(int i=1; i<arr.size(); i++) {
        vector<int> curr(target+1, 0);
        for(int tar=0; tar<=target; tar++) {
            int notTake = prev[tar];
            int Take = 0;
            if(arr[i] <= tar)    Take = prev[tar-arr[i]];
            curr[tar] = (notTake + Take)%MOD;
        }
        prev = curr;
    }
    return prev[target];
}


