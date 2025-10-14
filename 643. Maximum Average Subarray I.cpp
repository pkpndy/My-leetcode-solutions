class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<k) return 0;

        //compute sum of first window
        double sum=0;
        for(int i=0; i<k; i++) {
            sum += nums[i];
        }

        double maxAvg = sum/k;

        //slide the window
        for(int j=k; j<n; j++) {
            sum += nums[j] - nums[j-k]; // add new number, remove the number from the left
            maxAvg = max(maxAvg, sum/k);
        }

        return maxavg;
    }
};