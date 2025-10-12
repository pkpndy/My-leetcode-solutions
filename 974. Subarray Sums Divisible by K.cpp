class Solution {
public:
    // this is brute force approach that tries all possible subarrays
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0; 
        for(int i=0; i<nums.size(); i++) {
            int subsum=0;
            for(int j=i; j<nums.size(); j++) {
                subsum += nums[j];
                if(subsum % k == 0) {
                    count++;
                }
            }
        }
        return count;
    }

    /*
    Since subarray sum is: sum(l..r) = prefix[r] - prefix[l-1]
    We want: sum(l..r) % k == 0

    Plug the prefix formula in: (prefix[r] - prefix[l-1]) % k == 0
    
    → this means: prefix[r] % k == prefix[l-1] % k
    
    map will store these remainders with number of times it occurred

    |------S1----|
    {2, 3, 5, 4, 5, 3, 4}
    |-s2-|
    any subarray sum s1-s2 will be divisible by k if both on dividing by k give equal remainder
    
    */

    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remMap; //{remainder, count}
        int result=0;
        int prefixSum=0;
        remMap[0]=1; //base case: for 0 remainder we found 1 time 
        for(int i=0; i<nums.size(); i++) {
            prefixSum += nums[i];
            int remainder = prefixSum % k;
            
            //if remainder is -ve then 
            //if s is a sum and if k=7, and lets say remainder is -4
            // then 7s-4 = 7s-4 +7-7 = 7(s-1) + 7-4 = 7(s-1) + 3 hence we can store 3 as the remainder
            if(remainder<0) remainder += k;

            if(remMap.count(remainder)) {
                result += remMap[remainder]; //we add the number of times the remainder occurred
                remMap[remainder]++; //increase the count of this remainder
            } else {
                remMap[remainder]=1; //if this remainder was found for the first time
            }
        }
        return result;
    }
};