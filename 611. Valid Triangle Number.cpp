class Solution {
public:
  //sort the array and then two sum will be used
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        int count=0;
        int largest = nums.size()-1;
        while(largest>1) {
            int i=0, j=largest-1;
            while(i<j) {
                if(nums[i]+nums[j]>nums[largest]) {
                    count += (j - i); // since the numbers after i will always be greater, hence all are valid combo
                    j--; //
                } else {
                    i++;
                }
            }
            largest--;
        }       
        return count; 
    }
};
