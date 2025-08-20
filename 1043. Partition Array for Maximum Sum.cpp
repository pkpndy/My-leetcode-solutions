class Solution {
public:
    int msp(int i, vector<int>& arr, int k, vector<int>& dp) {
        int n = arr.size();
        if(i==n)   return 0; //if i completed means partition completed

        if(dp[i] != -1) return dp[i];

        int maxSum=0; //store the maxSum for this index
        int len=0, maxi=INT_MIN; //length to get the max value and maxi for what is the max in range i till k
        for(int j=i; j<min(n, i+k); j++) { //min(n, i+k) bcoz when i reaches n-2 position the i+k might cross the array
            len++;
            maxi = max(maxi, arr[j]); //to store the maximum within k range
            //we get the sum till this point, then partition it and call for next further partition
            int sum = (len*maxi) + msp(j+1, arr, k, dp);
            maxSum = max(sum, maxSum); //max sum of all the possible partitions
        }
        return dp[i] = maxSum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return msp(0, arr, k, dp); //msp(i) here f(i) means give me the max sum if the array range starts at i till end
    }

    //tabulated code
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1, 0);
        int n = arr.size();
        for(int i=n-1; i>=0; i--) {
            int maxSum=0;
            int len=0, maxi=INT_MIN;
            for(int j=i; j<min(n, i+k); j++) { 
                len++;
                maxi = max(maxi, arr[j]);
                int sum = (len*maxi) + dp[j+1];
                maxSum = max(sum, maxSum);
            }
            dp[i] = maxSum;
        }
        return dp[0];
    }
};