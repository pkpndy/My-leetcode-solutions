class Solution {
public:
    //TC : O(n X n X n)  SC : O(n X n) + O(n)
    int mc(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if(i>j) return 0; //if i crosses j there won't be any cost
        if(dp[i][j] != -1)  return dp[i][j];
        int mini = 1e9; //to calculate minimum we take max value

        //  0  1  3  4  5  7 => 7 is the length of the stick
        //     i        j
        
        //we will be traversing the cuts array itself which will start the first cut values one by one
        for(int ind=i; ind<=j; ind++) {
            int cost = (cuts[j+1] - cuts[i-1]) + mc(i, ind-1, cuts, dp) + mc(ind+1, j, cuts, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        //to calculate the cost(length of the current stick)
        cuts.insert(cuts.begin(), 0); //we insert a 0 at the begining
        cuts.push_back(n); //we push the length of the stick at the end
 
        //we sort the cuts array because we want the right partition always have higher values 
        //and left partition always have lower values
        sort(cuts.begin(), cuts.end());
 
        vector<vector<int>> dp(cuts.size(), vector<int> (cuts.size(), -1));
 
        //we pass i=1 because at the 0th index we have added zero for calculating the cost
        //we pass j=cuts.size()-2 because one -1 is for the last index 
        //and another -1 because at the last index we added the length of the stick
        return mc(1, cuts.size()-2, cuts, dp);
    }

    //tabulated solution
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        //we will take m+2 because after adding boundaries (0 and stick length) the cuts array size increased by 2
        vector<vector<int>> dp(m+2, vector<int> (m+2, 0));
 
        for(int i=m; i>=1; i--) { //we started from 1 not 0 as on 0th index we added 0
            for(int j=1; j<=m; j++) {
                int mini = 1e9;
                if(i>j) continue; //if i crosses j there won't be any cost
                for(int ind=i; ind<=j; ind++) {
                    int cost = (cuts[j+1] - cuts[i-1]) + dp[i][ind-1] + dp[ind+1][j];
                    mini = min(mini, cost);
                    dp[i][j] = mini;
                }
            }
        }
        return dp[1][m];
    }
};