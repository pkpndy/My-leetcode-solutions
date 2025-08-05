class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //subset means any combination of elements => no order, no continiuty
        //sort the nums array since order doesn't matter in subset
        //rest of the code will be same as printing LIS, only add the divisibilty check
        int n = nums.size();
        sort(nums.begin(), nums.end()); //since 
        vector<int> dp(n, 1), hash(n);
        int maxi = INT_MIN;
        int lastIdx = -1;

        for(int ind = 0; ind<n; ind++) {
            hash[ind] = ind;
            for(int prev=0; prev<ind; prev++) {
                //if the current element is divisible by previous element
                //if adding the LIS till previous element(1+dp[prev]) > LIS till current element(dp[ind]) till now
                if(nums[ind] % nums[prev] == 0 && 1 + dp[prev] > dp[ind]) {
                    dp[ind] = 1 + dp[prev];
                    hash[ind] = prev;
                }
            }

            if(dp[ind] > maxi) {
                maxi = dp[ind];
                lastIdx = ind;
            }
        }

        vector<int> res;
        res.push_back(nums[lastIdx]);
        while(hash[lastIdx] != lastIdx) {
            lastIdx = hash[lastIdx];
            res.push_back(nums[lastIdx]);
        }
        reverse(res.begin(), res.end());

        return res;
    }
};