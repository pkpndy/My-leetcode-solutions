class Solution {
public:
    // we will use two pointer approach
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for(int fast=0; fast<nums.size(); fast++) {
            if(nums[fast] != val) { // fast scans for element other than val
                swap(nums[slow], nums[fast]);
                slow++;
            }
        }
        return slow;
    }
};
