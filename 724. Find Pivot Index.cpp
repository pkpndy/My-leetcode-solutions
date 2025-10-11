class Solution {
public:
    //prefix sum approach
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0; //sum of all previous elements (before i).
        //here we are trying to check each index as the possible pivot
        for(int i=0; i<nums.size(); i++) {
            //total - leftSum - current element(pivot jiske pehle aur baad dekh rhe).
            int rightSum = total - leftSum - nums[i];
            if(leftSum == rightSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};