class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>> board) {
        vis[i][j]=1;
        int dr[]={-1, 0, 1, 0};
        int dc[]={0, -1, 0, 1};
        for(int k=0; k<4; k++) {
            int nr = i+dr[k];
            int nc = j+dc[k];
            if(nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size() && !vis[nr][nc] && board[nr][nc] == 'O') {
                dfs(nr, nc, vis, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));

        //since all the 'O' regions that are connected to the border can't be captured
        //hence we mark all the O regions connected to the border as visited
        for (int col = 0; col < n; ++col)                         // top row
            if (board[0][col] == 'O' && !vis[0][col])
                dfs(0, col, vis, board);

        for (int col = 0; col < n; ++col)                         // bottom row
            if (board[m-1][col] == 'O' && !vis[m-1][col])
                dfs(m-1, col, vis, board);

        for (int row = 0; row < m; ++row) {                     // left column
            if (board[row][0] == 'O' && !vis[row][0])
                dfs(row, 0, vis, board);

            if (board[row][n-1] == 'O' && !vis[row][n-1])         // right column
                dfs(row, n-1, vis, board);
        }

        //then we set 'X' to all the unvisited regions, 
        //this is capture the O regions not connected to the border
        for(int a=0; a<m; a++) {
            for(int b=0; b<n; b++) {
                if(!vis[a][b])  board[a][b] = 'X';
            }
        }
    }
};