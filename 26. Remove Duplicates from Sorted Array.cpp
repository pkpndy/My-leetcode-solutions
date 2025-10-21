class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() <= 1)    return nums.size();
        int i=0;
        for(int j=1; j<n; j++) {
            if(nums[i] != nums[j]) {
                i++; //the index next to current index
                nums[i] = nums[j]; //gets filled by the new number
            }
        }
        return i+1; //since it is 0 based hence return i+1
    }
};