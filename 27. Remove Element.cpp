class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        int rem=0;
        for(int x : nums) {
            if(x != val) {
                nums[k++]=x;
                rem++;
            }
        }
        return rem;
    }
};