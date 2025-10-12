class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1; 
        int maxArea=0;
        while(i<j) {
            //whichever is minimum will determine the amount of water that will be stored
            int h = min(height[i], height[j]);
            int currArea = (j-i)*h; //area of water stored
            maxArea = max(maxArea, currArea);
            //to maximize area, if we are decreasing width then we will keep the rod that is longer
            //and move the rod that has smaller height in hope of finding better height
            if(height[i]<=height[j]) { //if both have same height then move any
                i++;
            } else {
                j--;
            }
        }
        return maxArea;
    }
};