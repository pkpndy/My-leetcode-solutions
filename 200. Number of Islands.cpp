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
};