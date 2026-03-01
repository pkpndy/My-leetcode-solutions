class Solution {
public:
    void perm(vector<int>& nums, vector<int>& ds, vector<int>& vis, vector<vector<int>>& result) {
        if(ds.size() == nums.size()) {
            result.push_back(ds);
            return;
        }

        for(int i=0; i<nums.size(); i++) {
            // 1. Skip if already visited
            if(vis[i]) continue;

            // 2. Skip if it's a duplicate AND the previous one wasn't used
            // This '!vis[i-1]' is the key trick for unique permutations
            if(i > 0 && nums[i] == nums[i-1] && !vis[i-1]) continue;

            vis[i] = 1;
            ds.push_back(nums[i]);
            perm(nums, ds, vis, result);
            
            // Backtrack
            ds.pop_back();
            vis[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)    return {nums};

        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> ds;
        vector<int> vis(n, 0);
        perm(nums, ds, vis, result);

        return result;
    }
};