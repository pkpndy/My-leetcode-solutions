class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)    return nums.size();

        int slow = 0; // slow will keep the track of which element needs to be updated
        for(int fast=1; fast<nums.size(); fast++) { // fast will scan for next unique element
            if(nums[fast] != nums[slow]) { //jaise hi ek naya unique element mile
                slow++; // next index pe jao
                nums[slow] = nums[fast]; // uss naye unique element ko rkh do
            }
        }

        return slow+1; // kyuki slow is the index of unique udated element and plus 1 for the no. of elements
    }
};
