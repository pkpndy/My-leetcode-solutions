class Solution {
public:
    //recursive memoized solution
    int lts(int ind, int last, vector<int>& nums, vector<vector<int>>& dp) {
        if(ind==nums.size())    return 0;

        //we will do last+1 index shifting in dp array as in the very first call the last is -1
        //which gives error so we make the size n+1, and store the results in shifted index
        if(dp[ind][last+1] != -1) return dp[ind][last+1];

        int take = 0;
        if(last == -1 || nums[ind] > nums[last]) {
            take = 1 + lts(ind+1, ind, nums, dp);
        }
        int notTake = 0 + lts(ind+1, last, nums, dp);

        return dp[ind][last+1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return lts(0, -1, nums, dp);
    }

    //tabulated solution
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        // for(int i=0; i<=n; i++) { we dont need to to this as dp is initialised with 0
        //     dp[n][i] = 0;
        // }

        for(int ind=n-1; ind>=0; ind--) {
            for(int last=ind-1; last>=-1; last--) {
                int take = 0;
                if(last == -1 || nums[ind] > nums[last]) {
                    take = 1 + dp[ind+1][ind+1];
                }
                int notTake = 0 + dp[ind+1][last+1];

                dp[ind][last+1] = max(take, notTake);
            }
        }

        return dp[0][-1+1];
    }

    //space optimisation
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n+1, 0);

        for(int ind=n-1; ind>=0; ind--) {
            vector<int> curr(n+1, 0);
            for(int last=ind-1; last>=-1; last--) {
                int take = 0;
                if(last == -1 || nums[ind] > nums[last]) {
                    take = 1 + prev[ind+1];
                }
                int notTake = 0 + prev[last+1];

                curr[last+1] = max(take, notTake);
            }
            prev = curr;
        }

        return prev[-1+1];
    }

    //different algorithm solution (this helps in printing the LIS)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int ind=0; ind<n; ind++) {
            for(int last=0; last<ind; last++) {
                if(nums[last] < nums[ind]) {
                    dp[ind] = max(1 + dp[last], dp[ind]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }

    //binary search algo TC:O(nlogn)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        res.push_back(nums[0]);
        for(int i=1; i<n; i++) {
            if(nums[i] > res.back()) {
                // Case 1: nums[i] is greater than all elements in tails.
                // It extends the longest subsequence found so far.
                res.push_back(nums[i]);
            } else {
                // Case 2: nums[i] is smaller or equal to the end of tails.
                // We find the smallest element in tails that is >= nums[i]
                // and replace it with nums[i]. This creates a new potential
                // subsequence of the same length but with a smaller tail,
                // which is better for future extensions.

                // Find the position to replace in the 'tails' vector.
                int idx = lower_bound(res.begin(), res.end(), nums[i]) - res.begin(); //lower_bound uses binary search
                res[idx] = nums[i];
            }
        }

        return res.size();
    }
};