class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size())   return; //if out of bounds return
        if(grid[i][j] == '0' || vis[i][j]) return; //if not island or already visited return
        if(!vis[i][j] && grid[i][j] == '1') { //if not visited and is an island
            //mark as visited first as it will prevent infinite loop in later calls
            vis[i][j]=1;
            //check for its connected positons
            dfs(i, j+1, vis, grid);
            dfs(i+1, j, vis, grid);
            dfs(i, j-1, vis, grid);
            dfs(i-1, j, vis, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        vector<vector<int>> vis(m, vector<int> (n, 0));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    res++; //weeee started on a new island
                    dfs(i, j, vis, grid); //check for all the positions
                }
            }
        }

        return res;
    }

    //this is a little space optimised solution as we will mark the position itself as water
    void dfs(int i, int j, vector<vector<char>>& grid) {
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size())   return; //if out of bounds return
        if(grid[i][j] == '0') return; //if its water return
        if(grid[i][j] == '1') { //if it is an island
            //mark as water first as it will prevent infinite loop in later calls
            grid[i][j]='0';
            //check for its connected positons
            dfs(i, j+1, grid);
            dfs(i+1, j, grid);
            dfs(i, j-1, grid);
            dfs(i-1, j, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1') { //if its an island start the traversal
                    res++; //weeee started on a new island
                    dfs(i, j, grid); //check for all the positions
                }
            }
        }

        return res;
    }

    //bfs traversal implementation
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;

        queue<pair<int, int>> q; //for storing the row, column
        vector<vector<int>> vis(m, vector<int> (n, 0));

        //{up, right, down, left}
        int dr[] = {-1, 0, 1, 0}; //direction row
        int dc[] = {0, 1, 0, -1}; //direction column

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!vis[i][j] && grid[i][j] == '1') { //if it's a '1' and is not visited
                    res++; //weeeeee found an island
                    vis[i][j] = 1; //mark this positon as visited
                    q.push({i, j}); //push it in the queue

                    while(!q.empty()) { //keep exploring till all the connected positions are explored
                        auto [r, c] = q.front(); //extract the row, column from the front of queue
                        q.pop(); //pop the front rol, col pair

                        for(int k=0; k<4; k++) { //for checking all directions of the extracted position
                            int nr = r+dr[k]; //current row position + row direction
                            int nc = c+dc[k]; //current col position + col direction

                            //check if new row position or new column position are not out of bounds 0 <= pos < size
                            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] == '1' && !vis[nr][nc]) { 
                                vis[nr][nc] = 1; //mark this new position as visited and 
                                q.push({nr, nc}); //push it to the queue so that its connected positions can be checked
                            }
                        }
                    }
                }
            }
        }

        return res;
    }
};