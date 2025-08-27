#include<vector> //for vector
#include<set> //for set
#include<algorithm> //for sort function

void dfs(int i, int j, int br, int bc, int** arr, vector<vector<int>>& vis, //curr row , curr col, base row, base col
    set<vector<pair<int, int>>>& st, vector<pair<int, int>>& shape,  int n, int m)
{
    vis[i][j] = 1;
    //storing the difference from the base(starting point),
    //so that the same shape in different area of the matrix can be identified
    shape.push_back({br-i, bc-j});

    static int dr[] = {-1, 0, 1, 0};
    static int dc[] = {0, -1, 0, 1};

    for(int k=0; k<4; k++) {
        int nr = i+dr[k];
        int nc = j+dc[k];

        if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && arr[nr][nc] == 1) {
            dfs(nr, nc, br, bc, arr, vis, st, shape, n, m);
        }
    }
}

int distinctIslands(int** arr, int n, int m)
{
    vector<vector<int>> vis(n, vector<int> (m, 0));
    //set will store unique island shapes only, which will eliminate same shape islands
    set<vector<pair<int, int>>> st; //vector will store all the connected coordinates on a island

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            vector<pair<int, int>> shape;
            if(!vis[i][j] && arr[i][j] == 1) {
                //first i, j is for current position at any time,
                // second is for the base position from which we started traversal
                dfs(i, j, i, j, arr, vis, st, shape, n, m);
                //sort will make the same cordinates be at the same index in the vector,so set can reject the same vectors
                sort(shape.begin(), shape.end());
                st.insert(shape);
            }
        }
    }

    return st.size();
}