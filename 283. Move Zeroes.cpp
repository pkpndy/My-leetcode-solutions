class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k=0; //this points the current position that wants a non-zero
        //in this we first convert the zeros into non-zeros we get on the way
        for(int x : nums) {
            if(x != 0)  nums[k++] = x; //x checks for non-zero, that will be sent to the left
        }
        //then we convert the rest of the numbers into zeros
        while(k<nums.size()) {
            nums[k++]=0; //after the conversion ends we convert the left over numbers to 0
        }
    }
};