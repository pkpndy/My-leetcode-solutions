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
        int maxCol = 0, maxRow = 0; //stones is not the matrix but an array of coorndinates of the stones
        for(auto it: stones) {
            int row = it[0];
            int col = it[1];
            maxRow = max(row, maxRow); //largest row index in input
            maxCol = max(col, maxCol); //largest col index in input
        }

        //+2 because +1 for 0 based indexing to include maxRow(exact number) as 0 to n doesn't include the n,
        //another +1 to shift start the cols just after rows as adding only 0 will start the col node number
        //from the maxRow number 
        DisjointSet ds(maxRow + maxCol + 2);
        
        unordered_map<int, int> stoneNodes; //to keep track which nodes (rows and cols) are actually used in DS
        
        for(auto it: stones) { 
            int nodeRow = it[0]; //treat the rows as nodes
            int nodeCol = it[1] + maxRow + 1; //we shifted node no. of cols so they don't overlap with row node nos
            ds.unionBySize(nodeRow, nodeCol); //if a stone is at (row, col), connect row with col
            stoneNodes[nodeRow]=1; //we only care about unique keys (nodes), values don't matter
            stoneNodes[nodeCol]=1; //we only care about unique keys (nodes), values don't matter
        }

        int count=0;
        for(auto it: stoneNodes) { //iterate the map 
            if(ds.findUParent(it.first) == it.first) { //if the ultimate parent of the node is himself
                count++; //then it is a connected component
            }
        }
        int n=stones.size(); //n is the number of stones, and we have postions of stones in the array

        return n-count;
    }
};