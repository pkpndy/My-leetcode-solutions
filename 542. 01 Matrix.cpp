class Solution {
public:
    //we will use bfs here as we need to check the nearest 0, which is only possible if we check for 0
    //at every distance(level) like 1, 2, 3 and dfs wont work because it will go for depth of every number
    //and not explore all values at the same distance(level) and then move foward
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        //starting with -1 coz 0 is also a distance we can't use that, hence -1 will be considered unvisited
        vector<vector<int>> dist(m, vector<int> (n, -1));
        queue<pair<int, int>> q; //store the position

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0; //we start by marking all zeros as zero distance from the matrix
                    q.push({i, j}); //pushing there position to calculate the distance of all 1s from them
                }
            }
        }
        //pushing all the zeros first and then running bfs traversal marks the distance of all the adjacents from them

        //normal bfs traversal
        while(!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for(int k=0; k<4; k++) {
                int nr = r+dr[k];
                int nc = c+dc[k];

                //if the new row and new column is in bounds and unvisited
                if(nr>=0 && nc>=0 && nr<m && nc<n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1; //mark the adjacent positions with distance+1 from the zeros
                    q.push({nr, nc}); //push these new positions for marking their adjacent 1s distance from 0s
                }
            }
        }
        return dist;
    }
};