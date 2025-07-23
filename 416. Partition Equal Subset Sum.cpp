class Solution {
public:
    bool f(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(target==0)   return true; //if target is completed at any point
        if(i==0)    return nums[i]==target; //if target is completed at the 0th index

        if(dp[i][target] != -1) return dp[i][target]; //if result has already been calculated

        bool notTake = f(i-1, target, nums, dp); //not take the current element
        bool take = false; // if the element is greater than the target then false for not taking
        if(nums[i] <= target) { //if the element is smaller or equal to the target
            take = f(i-1, target - nums[i], nums, dp);
        }
        return dp[i][target] = notTake || take; //store and return the result of taking and not taking
    }

    bool canPartition(vector<int>& nums) {
        //we need to divide the nums such that subset1 == subset2
        //this means subset1==subset2==TotalSum/2
        //and if TotalSum is odd then return false as odd number can't be divided into two equal parts

        //HENCE WE ARE LOOKING FOR A SUBSE T WITH SUM TOALSUM/2
        //hence this is a question of subset with a target sum
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if(totalSum%2 != 0) return false; //odd sum case
        
        int target = totalSum/2;
        vector<vector<int>> dp(n, vector<int> (target+1, -1)); //+1 is needed as index is zero based
        return f(n-1, target, nums, dp);
    }

    /*
    //tabulated solution
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum%2 != 0)    return false;
        int total = totalSum/2;
        
        //+1 is needed as the indexing is zero based and we need to mark the exact number
        vector<vector<bool>> dp(n, vector<bool> (total+1, false));
        
        for(int j=0; j<n; j++) {
            dp[j][0] = true; //target 0 is always achievable at any index, not picking anything
        }
        if(nums[0] <= total) {
            dp[0][nums[0]] = true; // Only at 0th index, the number itself is possible target
        }

        for(int i=1; i<n; i++) { //we start after first row as we have marked whatever is achievable by the 0th index
            for(int j=1; j<=total; j++) { //we filled the entire target=0 column
                int notTake = dp[i-1][j];
                int take = false;
                if(nums[i] <= j) {
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j] = notTake || take;
            }
        }
    
        return dp[n-1][total];
    }
    */

    /*
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if(totalSum%2 != 0) return false; //odd sum case
        
        int target = totalSum/2;
        vector<int> prev(target+1, 0); //+1 is needed for result of last index
        
        for(int i=0; i<n; i++) {
            prev[0] = true; //target 0 is always achievable (empty subset) at any index
        }
        if(nums[0] <= target)   prev[nums[0]] = true;

        for(int i=1; i<n; i++) {
            vector<int> curr(target+1);
            curr[0] = true;
            for(int k=1; k<=target; k++) {
                bool notTake = prev[k];
                bool take = false;
                if(nums[i] <= k) {
                    take = prev[k-nums[i]];
                }
                curr[k] = notTake || take;
            }
            prev = curr;
        }

        return prev[target];
    }
    */
};