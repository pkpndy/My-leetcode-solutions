class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); //sort the array for using two pointer

        for(int i=0; i<nums.size()-2; i++) {
            if (i>0 && nums[i] == nums[i-1]) { //if i got a duplicate
                continue;
            }
            int j=i+1, k=nums.size()-1;
            while(j<k) { //we are doing two sum implementation here
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0) { //if we found the sum==0, then look further
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                    while (j<k && nums[j] == nums[j-1]) j++; //if j got a duplicate 
                    while (j<k && nums[k] == nums[k+1]) k--; //if k got a duplicate
                }

                else if(sum<0)   j++; //if sum is less than 0
                else   k--; //if sum is greater than 0
            }
        }
        return result;
    }
};
