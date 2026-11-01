class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i = 0; i < n-3; i++) { // we have to go till last 4th
            if(i > 0 && nums[i] == nums[i-1])  //ignore the duplicates, only consider the 1st occurance
                continue;
            for(int j = i+1; j < n-2; j++) {  //we have to go till last 3rd
                if(j > i+1 && nums[j] == nums[j-1]) //ignore the duplicates, only consider the 1st occurance
                    continue;
                int x = j+1, y = n-1;
                while(x < y) {
                    long long sum = (long long)nums[i] + nums[j] + nums[x] + nums[y];
                    if(sum == target) {
                        ans.push_back({nums[i], nums[j], nums[x], nums[y]});
                        x++;  //if we found the target then move both x and y
                        y--; //both because we want to try new combination
                        while(x < y && nums[x] == nums[x-1])
                            x++; //skip duplicates found for position x
                        while(x < y && nums[y] == nums[y+1])
                            y--; //skip duplicates found for position y
                    }
                    else if(sum < target) {
                        x++;
                    }
                    else {
                        y--;
                    }
                }
            }
        }
        return ans;
    }
};
