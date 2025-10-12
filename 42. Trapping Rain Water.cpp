class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int currMax=0;
        //we calculate the max from both directions to find vallies in which water will get trapped
        vector<int> lmax(n), rmax(n);
        for(int i=0; i<n; i++) {
            currMax=max(currMax, height[i]);
            lmax[i]=currMax;
        }
        currMax=0;
        for(int i=n-1; i>=0; i--) {
            currMax=max(currMax, height[i]);
            rmax[i] = currMax;
        }

        //the minimum of both the side of a valley will determine the amount of water that will
        //get stored in the valley and then the lowest points will give the water stored
        int waterTrapped=0;
        for(int i=0; i<n; i++) {
            waterTrapped += min(lmax[i], rmax[i]) - height[i];
        }

        return waterTrapped;
    }
};