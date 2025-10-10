//here we are counting the subarrays that are having sum equal to k
class Solution {
public:
    //this is O(N^2) solution - brute force approach
    int subarraySum(vector<int>& nums, int k) {
        int totalSubArrays=0;
        for(int i=0; i<nums.size(); i++) {
            int sum=0; //we calculate sum for all the subarrays starting from this i till j
            for(int j=i; j<nums.size(); j++) {
                sum += nums[j];
                if(sum==k)  totalSubArrays+=1;
            }
        }
        return totalSubArrays;
    }

    //this is prefixSum approach
    int subarraySum(vector<int>& nums, int k) {
        int totalSubArrays=0;
        unordered_map<int, int> prefix; // {sum, count}
        int prefixSum=0;
        //whenever we get a sum of a subarr starting from 0th index we store it because,
        //we will get the sum of a subarr excluding this subarr by doing prefix-k
        prefix[0]=1; //for subarrays that start that 0th index
        for(int i=0; i<nums.size(); i++) {
            prefixSum+=nums[i]; //we calculate the prefix sum from 0th index till i
            int remove = prefixSum-k; //sum of a subarray that's in between
            
            //this line works for all subarrays as if the subarray starts from 0th index
            //then the prefix[0]=1 that means sum 0 occurred 1 time helps
            totalSubArrays += prefix[remove]; //add the no. of times this subarray sum occurred
            
            prefix[prefixSum] += 1; //increase the count of this sum 
        }
        return totalSubArrays;
    }

};
