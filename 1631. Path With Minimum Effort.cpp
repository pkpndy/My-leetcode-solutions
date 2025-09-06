class Solution {
public:
    //effort max of all differences in the path
    //the path to be taken for minimum(which position to be picked next) is given by the pq
    //you just push the exploration and mark the difference
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        //store the minimum effort taken to reach this cell
        vector<vector<int>> minEffort(m, vector<int> (n, INT_MAX));

        //store the effort taken to reach this position, position of this cell {effort, {row, col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}}); //effort taken for the starting position and starting position is pushed
        minEffort[0][0] = 0; //store the minimum effort taken to reach the starting position

        static int dr[] = {-1, 0, 1, 0};
        static int dc[] = {0, 1, 0, -1};

        while(!pq.empty()) {
            //get the max effort taken to reach this position in the entire path
            int currentMaxEffort = pq.top().first;
            auto [r, c] = pq.top().second;
            pq.pop();

            //since pq gives the smallest everytime, this will be min effort to reach the destination
            if(r==m-1 && c==n-1)    return currentMaxEffort;

            for(int k=0; k<4; k++) {
                int nr = r+dr[k];
                int nc = c+dc[k];

                if(nr>=0 && nc>=0 && nr<m && nc<n) { //check for valid position
                    int effortOnThisJump = abs(heights[r][c] - heights[nr][nc]); //effort needed to jump on this position
                    //while storing any path the effort will be maximum of previous max effort or current effort
                    int effort = max(currentMaxEffort, effortOnThisJump); //
                    //absolute difference(current effort) earlier minimum effort for this position se km hona chahiye
                    if(effort < minEffort[nr][nc]) {
                        pq.push({effort, {nr, nc}}); //{maxEffort for this position, {position}}
                        minEffort[nr][nc] = effort; //store the minimum effort taken to reach this position
                    }
                }
            }
        }
        return 0;
    }
};