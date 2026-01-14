class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minlen=INT_MAX;
        int pfxsum=0;
        int i=0;
        for(int j=0; j<n; j++) { //keep expanding the window
            pfxsum += nums[j]; //keep increasing the sum

            while(pfxsum>=target) { //will prefixsum is >= target
                minlen=min(minlen, j-i+1); //calculate the minimum length
                pfxsum -= nums[i]; //decrease the sum as the number goes out of the window
                i++; //contract the window
            }
        }

        //since the question has asked to return 0 if result not found
        return (minlen==INT_MAX) ? 0 : minlen;
    }
};
