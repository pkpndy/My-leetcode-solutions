class Solution {
public:
    // this is the dutch flag pattern, which uses low, mid, high and the mid compared with pivot
    // in this question 1 will become the pivot
    void sortColors(vector<int>& nums) {
        int low=0, mid=0, high=nums.size()-1;
        while(mid<=high) { //if mid crosses high then stop, but dont stop when they meet
            if(nums[mid]<1) { //if the number we get is less than 1 then swap with low position
                swap(nums[low], nums[mid]);
                low++; mid++;
            } else if(nums[mid]==1) { //if it is exactly 1 then move ahead as it is in it's correct position
                mid++;
            } else { //if the number we get is more than 1 then swap with high that's its' correct position
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        return;
    }
};
