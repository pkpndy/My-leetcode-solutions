class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // we will store each number with its index, so that if in future we want to 
        // check it the required number to make target was found already once
        unordered_map<int, int> mpp;

        for(int i=0; i<nums.size(); i++) {
            int need = target - nums[i]; //the number we need to make the target
            if(mpp.count(need)) { //if the number we need to make the target is already present in the map
                return {mpp[need], i}; // return the index of both the numbers
            }
            mpp[nums[i]] = i; //if not found yet then markt the index of our current number and move ahead
        }
        return {};
    }
};
