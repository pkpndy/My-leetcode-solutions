class Solution {
public:
    /*
    //This is brute force recursive solution, TC:O(2^n) SC:O(n)
    int maxNoAdj(int i, vector<int>& nums) {
        //if the index reaches 0 it means it didn't pick index 1, hence return the value at 0
        if(i == 0)  return nums[0];
        //if it reaches index 1 and i-2 calls makes it negative call, then return 0
        if(i<0)     return 0;

        //if we pick our current element then we will pick the element after adjacent
        int pick = nums[i] + maxNoAdj(i-2, nums);
        //if we didn't pick the current element then we can pick the adjacent element
        int dontPick = 0 + maxNoAdj(i-1, nums);

        return max(pick, dontPick); //return the maximum of picking or not picking
    }
    int rob(vector<int>& nums) {
        return maxNoAdj(nums.size()-1, nums); //we start from n
    }
    */

    /*
    //This is memoized solution, TC:O(n) SC:O(n) + O(n)
    int maxNoAdj(int i,vector<int>& dp, vector<int>& nums) {
        if(i==0)    return nums[0];
        if(i<0) return 0;

        if(dp[i] != -1) return dp[i]; //return the result if already calculated once
        int pick = nums[i] + maxNoAdj(i-2, dp, nums);
        int notPick  = 0 + maxNoAdj(i-1, dp, nums);

        return dp[i] = max(pick, notPick); //store the result each time before returning
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1); //dp for storing the intermediate results
        return maxNoAdj(n-1, dp, nums); //we start from n
    }
    */

    /*
    //this is the tabulation form, we take bottom-up approach TC:O(n) SC:O(n)
    //think about the base cases and edge cases deeply
    int rob(vector<int>& nums) {
       int n = nums.size();
       vector<int> dp(n, -1);

       dp[0] = nums[0]; //we start by putting the 0th value as its needed for the calculation
       for(int i=1; i<n; i++) {
        int pick = nums[i]; //take the element
        //for case where the i-2 might result in negative index
        if(i>1) pick += dp[i-2]; //take the max from the non adjacent element
        
        int notPick = 0+dp[i-1]; //don't take the element and add the adjacent element max
        dp[i] = max(pick, notPick);
       }
        return dp[n-1]; //the last element will store the final max result
    }
    */

    //this is space optimised version, first convert to tabulation then come to this
    int rob(vector<int>& nums) {
       int n = nums.size();

       int prev = nums[0]; // case where index is 0
       int prev2 = 0; // case where index is less than 0
       for(int i=1; i<n; i++) {
        int pick = nums[i]; // we are taking the current element
        // only take the non adjacent previous when its index is greater than 0
        if(i>1) pick += prev2;
        
        int notPick = 0 + prev; //don't take current element, then we can take adjacent element
        int curr = max(pick, notPick); //store the max of taking or not taking
        prev2 = prev;
        prev = curr;
       }
        return prev; //in the end i goes out of the array of curr will go out and prev will remain
    }

};