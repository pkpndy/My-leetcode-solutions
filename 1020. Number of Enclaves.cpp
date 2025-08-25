class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid) {
        grid[i][j]=0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        for(int k=0; k<4; k++) {
            int nr = i+dr[k];
            int nc = j+dc[k];
            if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc] == 1) {
                dfs(nr, nc,grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //traversing the 1s found at the boundary
        int j=0, i=0;
        for(; i<m; i++) {
            if(grid[i][j] == 1) {
                dfs(i, j, grid);
            }
        }
        j=0; i=m-1;
        for(; j<n; j++) {
            if(grid[i][j] == 1) {
                dfs(i, j, grid);
            }
        }
        j=n-1; i=0;
        for(; i<m; i++) {
            if(grid[i][j] == 1) {
                dfs(i, j, grid);
            }
        }
        j=0; i=0;
        for(; j<n; j++) {
            if(grid[i][j] == 1) {
                dfs(i, j, grid);
            }
        }

        int count=0; //after converting boundary 1s count the 1s left
        for(int a=0; a<m; a++) {
            for(int b=0; b<n; b++) {
                if(grid[a][b] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};