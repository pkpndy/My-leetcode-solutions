class Solution {
private:
    void giveSubset(int idx, vector<int>& nums, vector<int> ds, vector<vector<int>>& res)
    {
        if(idx == nums.size()) { //if the recursion call by either take or not take reaches the end
            res.push_back(ds); //store the current created subset into result
            return;
        }

        ds.push_back(nums[idx]); //take 
        giveSubset(idx+1, nums, ds, res); //call the recursive function
        ds.pop_back(); //backtrack
        giveSubset(idx+1, nums, ds, res); //not take and call the recursive function
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res; //for returning the result having all subsets
        vector<int> ds; //for storing the subset 
        giveSubset(0, nums, ds, res);
        return res;
    }
};