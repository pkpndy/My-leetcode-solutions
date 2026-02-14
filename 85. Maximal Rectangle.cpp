class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        
        int maxArea=0;
        vector<int> height(m, 0); //we will use this to create a histogram

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == '1') height[j] += 1;
                else    height[j] = 0;
            }

            vector<int> NSR(m), NSL(m);
            stack<int> st;

            for(int j=0; j<m; j++) {
                while(!st.empty() && height[st.top()] >= height[j])    st.pop();
                NSL[j] = st.empty() ? 0 : st.top()+1; //actual rectangle start
                st.push(j);
            }
            
            while(!st.empty())  st.pop();
            
            for(int j=m-1; j>=0; j--) {
                while(!st.empty() && height[st.top()] >= height[j])   st.pop();
                NSR[j] = st.empty() ? m-1 : st.top()-1; //actual rectangle stop
                st.push(j);
            }

            for(int x=0; x<m; x++) {
                int width = NSR[x] - NSL[x] + 1;
                maxArea = max(maxArea, height[x]*width);
            }
        }
        return maxArea;
    }
};