class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow=0; // slow pointer for which index to swap
        for(int fast=0; fast<nums.size(); fast++) {
            if(nums[fast] != 0) { // scan for the non-zero elements so that they can be sent to the left
                swap(nums[slow], nums[fast]);
                slow++; // move to the next position
            }
        }
    }
};
