class DisjointSet {
    public:
        //we will keep size public because we want size of all the parents to be called directly
        //that means how many components are connected to this parent
        vector<int> parent, size;
        DisjointSet(int n) {
            parent.resize(n);
            size.resize(n, 1);
            for(int i=0; i<n; i++) {
                parent[i]=i;
            }
        }

        int findUParent(int node) {
            if(parent[node] == node)
                return node;
            return parent[node] = findUParent(parent[node]);
        }


        void unionBySize(int u, int v) {
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            if(ulp_u == ulp_v)  return;
            if(size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n); //all the cells will be treated as an individual node
        vector<int> nodes(n*n); //these are all the nodes
        //the relation between any cell being the node will be => (row*n)+col
        //row*n tells in which row the cell is present and plus col will give the exact column

        //step1: we created the connected components 
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) continue; //we are looking for 1, so skip 0
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                for(int k=0; k<4; k++) {
                    int nr = i+dr[k];
                    int nc = j+dc[k];
                    if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc] == 1) {
                        int nodeNo = (i*n)+j;
                        int adjNodeNo = (nr*n)+nc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        
        //step2: we check the size of the largest connected component formed by checking each 0 as 1
        int mx=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) continue; //we are looking for 0, so skip 1
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};

                //since incase the 0 is surrounded by 1s that belong to the same component
                //in that case same component size will be added again and again
                //so we take unique distnct parent components' size
                set<int> components; //these are the ultimate parent nodes of each distinct component
                //a new set is created everytime we find a 0

                for(int k=0; k<4; k++) {
                    int nr = i+dr[k];
                    int nc = j+dc[k];
                    //if the adjacent node is a 1 then it is a component
                    if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc] == 1) {
                        components.insert(ds.findUParent((nr*n) + nc)); //add the ultimate parent to the set
                    }
                }
                int sizeTotal=0; //calculate the size we get by converting this current 0 into 1
                for(auto it: components) { //traverse the set having ultimate parents for current 0
                    sizeTotal+=ds.size[it]; //add the sizes of all the ultimate parents
                }
                mx = max(mx, sizeTotal+1); //we add 1 to include current 1 we obtained by converting 0
            }
        }

        //in case the matrix has all 1s in that case, 
        //we will never find 0, so the above loop will skip everything
        for(int cellNo=0; cellNo<n*n; cellNo++) {
            //then we get the size of ultimate parent, since all the adjacent 1s will be connected to tihs
            mx = max(mx, ds.size[ds.findUParent(cellNo)]);
        }
        return mx;
    }
};