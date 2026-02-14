int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n==0)    return n;

        vector<int> NSL(n), NSR(n);
        stack<int> st;

        // find the nearest smaller to the left (NSL)
        for(int i=0; i<n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            // If stack is empty, no smaller element to the left; boundary is index 0
            NSL[i]=st.empty() ? 0 : st.top()+1;
            st.push(i);
        }

        while(!st.empty())  st.pop(); // empty the stack for reuse
        
        // find the nearest smaller to the right (NSR)
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            // If stack is empty, no smaller element to the right; boundary is index n
            NSR[i]=st.empty() ? n : st.top();
            st.push(i);
        }

        // calculate maximum area
        // area = heights[i] * (NSR[i] - NSL[i])
        int maxArea = 0;
        for(int i=0; i<n; i++) {
            int width = NSR[i] - NSL[i];
            maxArea = max(maxArea, heights[i]*width);
        }

        return maxArea;
    }
