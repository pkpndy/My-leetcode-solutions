class Solution {
public:
    //this is O(N^2) solution
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size()==0) return 0;
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n; i++) {
            int sum = 0;
            for(int j=i; j<n; j++) {
                sum += nums[j];
                if(sum==k) {
                    count++;
                }
            }
        }

        return count;
    }
};