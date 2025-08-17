class Solution {
public:
    int mc(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if(i>j) return 0; //we take i>j because i==j is also a valid problem

        if(dp[i][j] != -1)  return dp[i][j];

        int maxi = -1e9;
        for(int k=i; k<=j; k++) {
            //in this we start from picking last guy not first guy to get the formula
            //nums[i-1]*nums[k]*nums[i+1] this is the thing left if only one baloon is left
            //     1   *  [8]  *   1      if 8 is the last guy left out
            int coins = nums[i-1]*nums[k]*nums[j+1] + mc(i, k-1, nums, dp) + mc(k+1, j, nums, dp);
            //we don't start by picking the first guy bcoz it doesn't give independent subproblems 
            
            maxi = max(maxi, coins);
        }

        return dp[i][j] = maxi;
    }

    // 1 [3  1  5  8] 1     we add 1 to the left and right
    //    i        j

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int> (nums.size(), -1));
        //after inserting 1 in the begining, hence 0th index is occupied by 1
        return mc(1, nums.size()-2, nums, dp); //-2 because after pushing 1 in the end the last element is at n-2
    }

    //tabulated solution
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2, vector<int> (n+2, 0));

        for(int i=n; i>=1; i--) {
            for(int j=1; j<=n; j++) {
                if(i>j) continue;
                int maxi = -1e9;
                for(int k=i; k<=j; k++) {
                    int coins = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi = max(maxi, coins);
                    dp[i][j] = maxi;
                }
            }
        }
        return dp[1][n];
    }
}; 