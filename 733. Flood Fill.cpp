class Solution {
public:
    //this solution is using dfs traversal
    void dfs(int i, int j, int stclr, int color, vector<vector<int>>& vis, vector<vector<int>>& image) {
        if(i<0 || j<0 || i == image.size() || j == image[0].size()) return; //if out of bounds return
        if(vis[i][j] == 1 || image[i][j] != stclr)   return; //if not same as the starting color or visited then return 

        vis[i][j] = 1; //mark visited
        image[i][j] = color; //change the color or current position

        int dr[] = {-1, 0, 1, 0}; //direction row
        int dc[] = {0, -1, 0, 1}; //direction column

        for(int k=0; k<4; k++) {
            int nr = i+dr[k]; //current row position + row direction
            int nc = j+dc[k]; //current col position + col direction
            //check if new row position or new column position are not out of bounds 0 <= pos < size
            if(nr>=0 && nc>=0 && nr < image.size() && nc < image[0].size() && image[nr][nc] == stclr) {
                dfs(nr, nc, stclr, color, vis, image); //call the function again for subsequent positions
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int srcColor = image[sr][sc]; //starting color
        if(srcColor == color)   return image; //if original color and new color are same, no change is needed

        vector<vector<int>> vis(n, vector<int> (m, 0));
        dfs(sr, sc, srcColor, color, vis, image);

        return image;
    }

    //bfs traversal implementation
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int srcColor = image[sr][sc]; //starting color
        if(srcColor == color)   return image; //if original color and new color are same, no change is needed

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int> (m, 0));

        vis[sr][sc]=1; //mark starting node as visited
        q.push({sr, sc}); //push starting node to queue 

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            image[r][c] = color; //change the color of the current node

            for(int i=0; i<4; i++) {
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nc>=0 && nr>=0 && nr<n && nc<m && image[nr][nc]==srcColor && !vis[nr][nc]) {
                    vis[nr][nc]=1; //mark this node as visited and
                    q.push({nr, nc}); //push it to the queue
                }
            }
        }

        return image;
    }
};