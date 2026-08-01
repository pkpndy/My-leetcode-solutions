class Solution {
public:
    // this is two pointer approach, but works only for sorted arrays
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j=numbers.size()-1;
        while(i<j) {
            if(numbers[i] + numbers[j] == target) {
                return {i+1, j+1};
            } else if(numbers[i] + numbers[j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return {};
    }

    // this uses O(N) space
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mpp;
        vector<int> ans;
        for(int i=0; i<numbers.size(); i++) {
            int remaining = target - numbers[i];
            if(mpp.count(remaining)) {
                return {mpp[remaining]+1, i+1};
            }
            mpp[numbers[i]]=i;
        }
        return {};
    }
};
