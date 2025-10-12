class Solution {
public:
    //remember 3sum has implementation of 2sum involved
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 3) return result; //if the nums array is smaller than 3 then return the empty array
        sort(nums.begin(), nums.end()); //sort the array since it hasn't asked for indexes
        
        for(int i=0; i<n-2; i++) { //this will be the first number of the triplet
            //skip the very first number of the triplet if its
            //already been used once to create a triplet
            if(i>0 && nums[i]==nums[i-1])   continue; //skip the entire iteration

            int left=i+1; //this will be the second number of the triplet
            int right=n-1; //this will be the third number of the triplet

            while(left < right) { //we are doing two sum implementation here
                int sum = nums[i]+nums[left]+nums[right];
                if(sum==0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    //since these numbers are added to the result
                    //we skip the numbers so that they don't create duplicates
                    while(left<right && nums[left] == nums[left+1])   left++;
                    while(left<right && nums[right] == nums[right-1]) right--;

                    //move the iterators forward after these numbers have been pushed
                    left++;
                    right--;
                }
                else if(sum<0)  left++; //if the sum we got is less than 0 then increase left
                else    right--; //else decrease right for sum more than 0
            }
        }
        return result;
    }
};