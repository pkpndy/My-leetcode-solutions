class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0; //to store the LIS length from the dp array
        //count to store the number of LIS at each index,
        //setting 1 bcoz the LIS count will atleast be 1 for each element
        vector<int> dp(n, 1), count(n, 1); //dp is set 1 as the LIS length will atleast be 1, that is the element itself
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) { //j<i will help in not including the current number for checking
                //if nums[j] can be attached to nums[i] && if LIS length of nums[j] is greater than nums[i]
                if(nums[i] > nums[j] && 1+dp[j] > dp[i]) {
                    dp[i] = dp[j] + 1; //all the LIS of nums[j] will also be LIS for nums[i]
                    count[i] = count[j]; //hence assign its count to nums[i], since it has higher LIS
                } 
                //if attaching nums[j] to nums[i], makes an equal equal length LIS
                else if(nums[i] > nums[j] && 1+dp[j] == dp[i]) { //checking if nums[j] can be attached to nums[i]
                    dp[i] = dp[j] + 1; //all the LIS of nums[j] will also be LIS for nums[i]
                    count[i] += count[j]; //then counts will be added
                }
            }
            maxi = max(dp[i], maxi); //storing the length of LIS
        }

        int nos = 0; //to store the number of LIS
        for(int i=0; i<n; i++) {
            if(dp[i] == maxi) { //since dp array is storing the LIS till i, hence the we check if it's the longest
                nos+=count[i]; //if it's longest then add the count of the same length LIS
            }
        }

        return nos;
    }
};