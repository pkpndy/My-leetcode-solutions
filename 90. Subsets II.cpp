/*
Call(idx=0, ds=[]):
├── Add [] ✓ (current subset)
├── i=0: nums[0]=1, ds=[1]
│   └── Call(idx=1, ds=[1]):
│       ├── Add [1] ✓ (current subset)
│       ├── i=1: nums[1]=2 (first 2), ds=[1,2]
│       │   └── Call(idx=2, ds=[1,2]):
│       │       ├── Add [1,2] ✓ (current subset)
│       │       └── i=2: nums[2]=2 (second 2), ds=[1,2,2]
│       │           └── Call(idx=3, ds=[1,2,2]):
│       │               └── Add [1,2,2] ✓ (current subset)
│       └── i=2: nums[2]=2 (second 2)
│           ├── Skip! (i=2 > idx=1 && nums[2] == nums[1]) → continue
├── i=1: nums[1]=2 (first 2), ds=[2]
│   └── Call(idx=2, ds=[2]):
│       ├── Add [2] ✓ (current subset)
│       └── i=2: nums[2]=2 (second 2), ds=[2,2]
│           └── Call(idx=3, ds=[2,2]):
│               └── Add [2,2] ✓ (current subset)
└── i=2: nums[2]=2 (second 2)
    └── Skip! (i=2 > idx=0 && nums[2] == nums[1]) → continue
*/

//  "I have a valid subset right now. Let me also try extending it with remaining elements."

/*
Why add immediately?
Every recursive call represents a valid subset at that point
We're not "building towards" a complete subset - we already have one
We're extending the current subset by trying different elements
*/
class Solution {
private:
    void giveSubsets(int idx, vector<int>& nums, vector<int>& ds, vector<vector<int>>& res)
    {
        res.push_back(ds);   

        for(int i=idx; i<nums.size(); i++) {
            if(i>idx && nums[i] == nums[i-1])   continue;
            ds.push_back(nums[i]);
            //we dont call for idx+1 because it might call the function for duplicates
            //i has skipped duplicates, so i+1 will give us the new number after duplicates
            giveSubsets(i+1, nums, ds, res);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0)    return res;
        vector<int> ds;
        sort(nums.begin(), nums.end()); //always sort coz the question didn't say nums is sorted
        giveSubsets(0, nums, ds, res);
        return res;
    }
};