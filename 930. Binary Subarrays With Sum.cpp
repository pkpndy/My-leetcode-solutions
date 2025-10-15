class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count=0;
        int pfxSum=0;

        //{pfxSum, number of subarrays that have this sum and end here}
        unordered_map<int, int> pfxCount;
        pfxCount[0]=1; //the sum 0 was found once at the begining

        for(int it: nums) {
            pfxSum += it; //it because in this type of for loop it holds the value at each index

            //for any subarraysum to be equal to goal, 
            //prefixSum of that subarray if is x, then inside it there is sum=goal subarray
            //then to get how x-goal subarraysums we use this map 
            if(pfxCount.count(pfxSum-goal)) {
                count += pfxCount[pfxSum-goal];
            }

            //push this prefix sum into map, so that we can also check if removing this subarray
            //is giving the sum=goal for some other subarray
            pfxCount[pfxSum]++;
        }
        return count;
    }
};