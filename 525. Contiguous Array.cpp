class Solution {
public:
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