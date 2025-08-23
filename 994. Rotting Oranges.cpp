class Solution {
public:
    //this question can't be solved using dfs as the rotting is happening breadth first way,
    //expanding in all directions not depth first way

    //bfs traversal
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0)); //visited array to mark rotten and visited
        //store the position and also the time at this level, so next level can pick up from here
        queue<pair<pair<int, int>, int>> q;
        int countFresh=0; //initial fresh oranges count

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==2) { //if the orange is rotten
                    vis[i][j] = 2; //mark it as rotten
                    q.push({{i, j}, 0}); //store its position and also level(time)
                }
                if(grid[i][j]==1)   countFresh++; //count the fresh orange
            }
        }

        int dr[] = {-1, 0, 1, 0}; //direction row
        int dc[] = {0, -1, 0, 1}; //direction column
        int time = 0; //total time taken(levels)

        while(!q.empty()) {
            int r = q.front().first.first; //get the row
            int c = q.front().first.second; //get the column
            int t = q.front().second; //get the time(level) at that rotten orange
            time = max(time , t); // our current max time is more or time at previous level
            q.pop();

            for(int k=0; k<4; k++) { //check for all directions
                int nr = r+dr[k];
                int nc = c+dc[k];
                //if the adjacent orange is fresh and unvisited
                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc] == 1 && !vis[nr][nc]) {
                    vis[nr][nc]=2; //rot this adjacent orange
                    q.push({{nr, nc}, t+1}); //push this orange position and with increased time
                    countFresh--; //decrease the count of fresh oranges left
                }
            }
        }

        if(countFresh) return -1; //if there are still fresh oranges left, then return -1

        return time;
    }
};