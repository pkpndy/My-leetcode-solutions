class Solution {
public:
    //this is recursive solution that will take time O(N^2) and space O(N^2)
    int giveJumps(int index, vector<int>& nums, vector<int>& dp) {
        if(index>=nums.size()-1)    return 0; //if reached last or beyond then no need to jump
        if(dp[index] != -1) return dp[index];
        int mini = INT_MAX; //to store minimum jumps required to reach this index
        //for each index, we try making all the jumps till the value of this element 
        //and calculate the minimum jumps required to reach all the indexes from here
        for(int i=1; i<=nums[index]; i++) {
            //each time the jump will be from just the next number till the value in the index
            int nextIndex = index + i;
            if(nextIndex < nums.size()) { //if the nextIndex we are getting is within bounds
                int res = giveJumps(nextIndex, nums, dp); //call for each of the indexes that we can reach from this current index

                if(res != INT_MAX) { //if we really reached end from the nextIndex
                    mini = min(mini, 1+res); //1 for this jump + res for the rest
                }
            }
        }
        return dp[index] = mini;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return giveJumps(0, nums, dp);
    }

    //greedy algo TC: O(N) and SC:O(1)
    int jump(vector<int>& nums) {
        int n = nums.size();
        //here are going with range based approach in which we calculate the farthest range from the current range,
        //and place r at the farthest of the next range and l just after the end of current range
        int l=0, r=0, jumps=0;
        while(r<n-1) {
            int farthest=r; //store farthest because r can't be changed everytime
            for(int k=l; k<=r; k++) { //look for the max that can be reached from the current range
                //k means current index + nums[k] means the distance till where we can jump
                farthest=max(k+nums[k], farthest);
            }
            l=r+1; //place l just after the current range
            r=farthest; //place r at the farthest
            jumps++; //increase the jumps
        }
        return jumps;
    }
};