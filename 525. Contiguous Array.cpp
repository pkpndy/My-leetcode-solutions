class Solution {
public:
    //this is brute force approach where we try all the subarrays
    int findMaxLength(vector<int>& nums) {
        int maxLen=0;
        for(int i=0; i<nums.size(); i++) {
            int sum=0; //sum should be inside because we calculate sum for every subarray starting with i
            for(int j=i; j<nums.size(); j++) {
                if(nums[j]==0) {
                    sum--;
                } else {
                    sum++;
                }
                if(sum==0) {
                    maxLen=max(maxLen, j-i+1); //i+1 because if i and j are both at the same element then length should be 1 not 0
                }
            }
        }
        return maxLen;
    }

    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> firstSeen; // {prefixSum -> index}
        firstSeen[0]=-1; //base: before array starts
        int prefixSum=0;
        int maxLen=0;

        for(int i=0; i<nums.size(); i++) {
            //calculate the prefix sum till this index
            //if found 1 then add 1 else add -1
            prefixSum += (nums[i] == 1 ? 1 : -1);

            //if we have seen this sum before,
            //subarray between previous index+1 .. i has equal 0s & 1s
            if(firstSeen.count(prefixSum)) { //.count gives the number of occurances of any key
                maxLen = max(maxLen, i-firstSeen[prefixSum]); 
            } else {
                firstSeen[prefixSum] = i; //store if this sum was found first time
            }
        }

        return maxLen;
    }
};
