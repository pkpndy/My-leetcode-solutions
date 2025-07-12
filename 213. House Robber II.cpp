class Solution {
public:
    //this problem is same as the house robber 1,
    //with the only difference is we can't choose the first and the last both
    int rob(vector<int>& nums) {
        if(nums.size() == 1)    return nums[0];
        int n = nums.size();

        vector<int> temp1, temp2;
        //we create an array having the last element (excluding the first element)
        for(int i=1; i<n; i++) {
            temp1.push_back(nums[i]);
        }
        //we create an array having the first element (excluding the last element)
        for(int i=0; i<n-1; i++) {
            temp2.push_back(nums[i]);
        }
        //the we simply calculate which array will give use the max
        //by passing them to house robber 1 code
        int ans = max(maxNoAdj(temp1), maxNoAdj(temp2));
        return ans;
    }

    int maxNoAdj(vector<int>& nums) 
    {
        int n = nums.size();

       int prev = nums[0]; // case where index is 0
       int prev2 = 0; // case where index is less than 0
       for(int i=1; i<n; i++) {
        int pick = nums[i]; // we are taking the current element
        // only take the non adjacent previous when its index is greater than 0
        if(i>1) pick += prev2;
        
        int notPick = 0 + prev; //don't take current element, then we can take adjacent element
        int curr = max(pick, notPick); //store the max of taking or not taking
        prev2 = prev;
        prev = curr;
       }
        return prev; //in the end i goes out of the array of curr will go out and prev will remain
    }
};