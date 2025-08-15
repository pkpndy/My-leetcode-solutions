/*
Given a chain of matrices A1, A2, A3,.....An. Your task is to find out the minimum cost to multiply these matrices. The cost of matrix multiplication is defined as the number of scalar multiplications. 
A Chain of matrices A1, A2, A3,.....An is represented by a sequence of numbers in an array ‘arr’ where the dimension of 1st matrix is equal to arr[0] * arr[1] , 2nd matrix is arr[1] * arr[2], and so on.

For example:
For arr[ ] = { 10, 20, 30, 40}, matrix A1 = [10 * 20], A2 = [20 * 30], A3 = [30 * 40]

Scalar multiplication of matrix with dimension 10 * 20 is equal to 200.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
2
4
4 5 3 2
4
10 15 20 25
Sample Output 1:
70
8000
Sample Output Explanation 1:
In the first test case, there are three matrices of dimensions A = [4 5], B = [5 3] and C = [3 2]. The most efficient order of multiplication is A * ( B * C).
Cost of ( B * C ) = 5 * 3 * 2 = 30  and (B * C) = [5 2] and A * (B * C) = [ 4 5] * [5 2] = 4 * 5 * 2 = 40. So the overall cost is equal to 30 + 40 =70.

In the second test case, there are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.

If we multiply in order- A1*(A2*A3), then the number of multiplications required is 11250.

If we multiply in order- (A1*A2)*A3, then the number of multiplications required is 8000.

Thus a minimum number of multiplications required is 8000. 
*/

#include <bits/stdc++.h> 

//TC = O(N x N x N)  SC = O(N x N) +O(N)
int minops(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
    if(i==j)    return 0; //at i==j no steps will be performed
    if(dp[i][j] != -1)  return dp[i][j];
    int mini = 1e9; //we want to calculate the min, hence taking the max value
    for(int k=i; k<j; k++) { //k=i to j-1 because after partition there is k and k+1
        int steps = arr[i-1] * arr[k] * arr[j] 
                    + minops(i, k, arr, dp) 
                    + minops(k+1, j, arr, dp);
        
        mini = min(mini, steps); //calculate the minimum of all the steps
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int> (N, -1));
    //we start with 1 bcoz the size of any matrix from the array is arr[i-1] X arr[i]
    return minops(1, N-1, arr, dp);
}