class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0; //store the max index that can be reached by jump
        for(int i=0; i<nums.size(); i++) {
            if(maxJump<i)  return false; //if the current index can't be reached by the max jump form any of the index
            maxJump = max(maxJump, i+nums[i]); //calculate the maxJump from all the indexes
        }
        return true;
    }
};