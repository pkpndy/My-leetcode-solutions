class Solution {
public:
    //recursive memoised solution
    int giveWays(int n, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(n==0) {
            if(target == 0 && nums[0] == 0) return 2; //if last element is 0
            //if last is euqal to target, then taking is 1 way and 
            //if not euqal then not taking is a way
            else if(target==0 || nums[0] == target)  return 1;
            else return 0;   
        }

        if(dp[n][target] != -1) return dp[n][target];

        int notTake = giveWays(n-1, target, nums, dp);
        int take = 0;
        if(nums[n] <= target)   take = giveWays(n-1, target-nums[n], nums, dp);
        return dp[n][target] = take+notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        
        if(total-target < 0 || (total-target)%2)    return 0;
        int S2 = (total-target)/2;
        
        vector<vector<int>> dp(n, vector<int> (S2+1, -1));
        
        return giveWays(n-1, S2, nums, dp);
    }

    //tabulated solution
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        
        if(total-target < 0 || (total-target)%2)    return 0;
        int S2 = (total-target)/2;
        
        vector<vector<int>> dp(n, vector<int> (S2+1, 0));
        
        if(nums[0] == 0)    dp[0][0] = 2;
        else    dp[0][0] = 1;

        if(nums[0] != 0 && nums[0] <= S2)   dp[0][nums[0]] = 1;

        for(int i=1; i<nums.size(); i++) {
            for(int j=0; j<=S2; j++) {
                int notTake = dp[i-1][j];
                int take = 0;
                if(nums[i] <= j)   take = dp[i-1][j-nums[i]];
                dp[i][j] = take+notTake;
            }
        }
        return dp[n-1][S2];
    }

    //space optimised solution
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        
        if(total-target < 0 || (total-target)%2)    return 0;
        int S2 = (total-target)/2;
        
        vector<int> prev(S2+1, 0);
        
        if(nums[0] == 0)    prev[0] = 2;
        else    prev[0] = 1;

        if(nums[0] != 0 && nums[0] <= S2)   prev[nums[0]] = 1;

        for(int i=1; i<nums.size(); i++) {
            vector<int> curr(S2+1, 0);
            for(int j=0; j<=S2; j++) {
                int notTake = prev[j];
                int take = 0;
                if(nums[i] <= j)   take = prev[j-nums[i]];
                curr[j] = take+notTake;
            }
            prev = curr;
        }
        return prev[S2];
    }

    //my initial solution
    int giveWays(int n, int target, vector<int>& nums, vector<vector<int>>& dp, int offset) {
        if(n<0 && target==0)   return 1;
        else if(n<0)   return 0;

        if (target + offset < 0 || target + offset >= dp[0].size()) return 0;

        if(dp[n][target+offset] != -1) return dp[n][target+offset];

        int pos = giveWays(n-1, target-nums[n], nums, dp, offset);
        int neg = giveWays(n-1, target+nums[n], nums, dp, offset);

        return dp[n][target+offset] = pos+neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int offset = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int> (2 * offset +1, -1));
        return giveWays(n-1, target, nums, dp, offset);
    }
};