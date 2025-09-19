class DisjointSet {
    vector<int> parent, sizeP;
    public:
        DisjointSet(int n) {
            sizeP.resize(n, 1);
            parent.resize(n);
            for(int i=0; i<n; i++) {
                parent[i]=i;
            }
        }

        int findUParent(int node) {
            if(node == parent[node])
                return node;
            return parent[node] = findUParent(parent[node]);
        }

        void unionBySize(int u, int v) {
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            if(ulp_u == ulp_v)  return;
            if(sizeP[ulp_u] < sizeP[ulp_v]) {
                parent[ulp_u] = ulp_v;
                sizeP[ulp_v] += sizeP[ulp_u];
            } else {
                parent[ulp_v] = ulp_u;
                sizeP[ulp_u] += sizeP[ulp_v];
            }
        }
};

class Solution {
public:
    //if two stones are in the same row or same column then they are connected
    //and in this connected components if we start removing stones then the last left stone 
    //will have no component connected to it hence it can't be removed

    //so if a component (c1) has x1 nodes then the number of stones that can be removed will be x1-1
    //so the total number of stones that can be removed (from each component) will be
    // (x1-1) + (x2-1) + (x3-1) + (x4-1) ....... (xN-1) => (x1+x2+x3+x4+x5...) - (1+1+1+1+1....)
    //this becomes answer = numberOfStones - numberOfComponents

    //in the DisjointSet we will treat each row and column as a node, not each cell
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int m = stones[0].size();
        vector<vector<int>> mat(n, vector<int> (m, 0));
        DisjointSet ds(n*m);

        for(auto it: stones) {
            int x = it[0];
            int y = it[1];
            mat[x][y]=1;
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j]==0)    continue;
                int nodeNo = (i*n)+j;
                for(int k=0; k<4; k++) {
                    int nr = i+dr[k];
                    int nc = j+dc[k];
                    if(nr>=0 && nc>=0 && nr<n && nc<m && mat[nr][nc]==1) {
                        int adjNodeNo = (nr*n)+nc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    } 
                }
            }
        }
    }
};