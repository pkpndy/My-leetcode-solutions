class Solution {
public:
    //effort max of all differences in the path
    //the path to be taken for minimum(which position to be picked next) is given by the pq
    //you just push the exploration and mark the difference
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> mineffort(m, vector<int> (n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        mineffort[0][0] = 0;
        pq.push({0, {0, 0}});

        static int dr[] = {0, -1, 0, 1};
        static int dc[] = {-1, 0, 1, 0};

        while(!pq.empty()) {
            int maxeffort = pq.top().first;
            auto [r, c] = pq.top().second;
            pq.pop();
            if(r == m-1 && c == n-1)    return maxeffort;

            for(int k=0; k<4; k++) {
                int nr = r+dr[k];
                int nc = c+dc[k];

                if(nr>=0 && nr<m && nc>=0 && nc<n) {
                    int currdiff = abs(heights[r][c] - heights[nr][nc]);
                    //maximum effort encountered so far on the path till this neighbor.
                    int neweffort = max(currdiff, maxeffort); 
                    if(mineffort[nr][nc] > neweffort) {
                        mineffort[nr][nc] = neweffort;
                        pq.push({neweffort, {nr, nc}}); 
                    }
                }
            }
        }

        return 0;
    }
};