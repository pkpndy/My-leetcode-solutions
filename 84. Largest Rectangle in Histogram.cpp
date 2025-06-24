int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stack; // pair{index, height}
        int maxArea = 0;

        for(int i=0; i<heights.size(); i++) {
            int start = i; //start of the i from which the area has to calculated
            while(!stack.empty() && stack.top().second > heights[i]) {
                //till the current height is smaller than previous heights
                auto pair = stack.top();
                int index = pair.first;
                int height = pair.second;
                maxArea = max(maxArea, height * (i - index));
                start = index; //start idx of new i from which area has to be calculated
                stack.pop();
            }
            //push the start index for this height
            stack.push({start, heights[i]});
        }

        // for all the rectangles that had no smaller height after them
        while(!stack.empty()) {
            auto pair = stack.top();
            int index = pair.first;
            int height = pair.second;
            //we are converting .size() into int because it returns size_t data type
            maxArea = max(maxArea, height * (static_cast<int>(heights.size()) - index));
            stack.pop();
        }
        return maxArea;
    }