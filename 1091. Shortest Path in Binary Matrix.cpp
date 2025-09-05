class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //if first and last cell are not 0 then we cant start or end
        if(grid[0][0] != 0 || grid[m-1][n-1] != 0)  return -1;
        vector<vector<int>> dist(m, vector<int> (n, INT_MAX)); //storing the min distance of reaching that cell
        //we are goin to sort on the basis of distance, {distance, {row, col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({1, {0,0}}); //{length on start, {start row, start col}}
        dist[0][0] = 1; //mark the distance as 1

        //take care of the directions, because it gives error when paired worng
        int dr[] = {-1, -1, -1, 0, 1, 1, 1, -1}; 
        int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};


        while(!pq.empty()) {
            int currDist = pq.top().first;
            auto [x, y] = pq.top().second;
            pq.pop();
            for(int k=0; k<8; k++) {
                int nr = x + dr[k];
                int nc = y + dc[k];

                //if grid[row][col]==0 and the new path has less distance for this cell than any earlier path
                if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==0 && currDist+1 < dist[nr][nc]) {
                    pq.push({currDist+1, {nr, nc}}); //push the distance and the cell
                    dist[nr][nc] = currDist+1; //store the new minimum distance to reach this cell
                }
            }
        }
        return dist[m-1][n-1] == INT_MAX ? -1 : dist[m-1][n-1]; //if the last cell was reached or not
    }
};