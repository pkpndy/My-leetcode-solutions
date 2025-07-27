/*
You are given ‘n’ items with certain ‘profit’ and ‘weight’ and a knapsack with weight capacity ‘w’.
You need to fill the knapsack with the items in such a way that you get the maximum profit. You are allowed to take one item multiple times.

Example:
Input: 
'n' = 3, 'w' = 10, 
'profit' = [5, 11, 13]
'weight' = [2, 4, 6]

Output: 27

Explanation:
We can fill the knapsack as:

1 item of weight 6 and 1 item of weight 4.
1 item of weight 6 and 2 items of weight 2.
2 items of weight 4 and 1 item of weight 2.
5 items of weight 2.

The maximum profit will be from case 3 = 11 + 11 + 5 = 27. Therefore maximum profit = 27.
*/

//recursive memoized solution
int maxp(int n, int capacity, vector<int>& profit, vector<int>& weight, vector<vector<int>>& dp) {
    if(n==0) {
        return (capacity / weight[0]) * profit[0];  // Take as many times as possible    
    }

    if(dp[n][capacity] != -1) return dp[n][capacity];

    int notTake = 0 + maxp(n-1, capacity, profit, weight, dp);
    int take = 0;
    if(weight[n] <= capacity)  take = profit[n] + maxp(n, capacity-weight[n], profit, weight, dp);

    return dp[n][capacity] = max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int> (w+1, -1));
    return maxp(n-1, w, profit, weight, dp);
}

//tabulated solution
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    int capacity = w;
    vector<vector<int>> dp(n, vector<int> (w+1, 0));
    for(int i=0; i<=capacity; i++) {
        if(i/weight[0] != 0) dp[0][i] = (i/weight[0]) * profit[0];
        else dp[0][i] = 0;
    }

    for(int i=1; i<n; i++) {
        for(int j=0; j<=capacity; j++) {
            int notTake = 0 + dp[i-1][j];
            int take = 0;
            if(weight[i] <= j)  
            take = profit[i] + dp[i][j-weight[i]];
            dp[i][j] = max(take, notTake);
        }
    }

    return dp[n-1][capacity];
}

//space optimised solution
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    int capacity = w;
    vector<int> prev(w+1, 0);
    for(int i=0; i<=capacity; i++) {
        if(i/weight[0] != 0) prev[i] = (i/weight[0]) * profit[0];
        else prev[i] = 0;
    }

    for(int i=1; i<n; i++) {
        vector<int> curr(w+1, 0);
        for(int j=0; j<=capacity; j++) {
            int notTake = 0 + prev[j];
            int take = 0;
            if(weight[i] <= j)  
            take = profit[i] + curr[j-weight[i]];
            curr[j] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[capacity];
}