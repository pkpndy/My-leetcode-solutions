/*
Call(idx=0): nums[0]=1
├── TAKE 1: ds=[1]
│   └── Call(idx=1): nums[1]=2  
│       ├── TAKE 2: ds=[1,2] → Add [1,2]
│       └── NOT TAKE 2: ds=[1] → Add [1]
└── NOT TAKE 1: ds=[]
    └── Call(idx=1): nums[1]=2
        ├── TAKE 2: ds=[2] → Add [2]  
        └── NOT TAKE 2: ds=[] → Add []
*/

//  "I'm building a subset by making decisions. Only add when all decisions are made."

/*
Why check idx == nums.size()?

We make exactly one decision per element (take or not take)
We only have a complete subset when we've decided about all elements
We add to result only at the leaf nodes of recursion tree
*/

class Solution {
private:
    void giveSubset(int idx, vector<int>& nums, vector<int> ds, vector<vector<int>>& res)
    {
        if(idx == nums.size()) { //if the recursion call by either take or not take reaches the end
            res.push_back(ds); //store the current created subset into result
            return;
        }

        //TAKE the current element
        ds.push_back(nums[idx]); //take 
        giveSubset(idx+1, nums, ds, res); //decide for the next element
        ds.pop_back(); //backtrack
        //NOT TAKE the current element
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