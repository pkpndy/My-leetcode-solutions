#include<set>

class DisjointSet {
	vector<int> parent, pSize;
	public:
		DisjointSet(int n) {
			pSize.resize(n, 1);
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
			if(ulp_u == ulp_v)	return;
			if(pSize[ulp_u] < pSize[ulp_v]) {
				parent[ulp_u] = ulp_v;
				pSize[ulp_v] += pSize[ulp_u];
			}
			else {
				parent[ulp_v] = ulp_u;
				pSize[ulp_u] += pSize[ulp_v];
			}
		}
};

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	//n=>rows, m=>cols
	DisjointSet ds(n*m); //for cells to be represented as nodes
	//matrix to hold the islands and check for connected components
	vector<vector<int>> mat(n, vector<int> (m, 0));
	vector<int> ans; //store the answer
	int count=0; //current count of islands till now

	int dr[] = {-1, 0, 1, 0};
	int dc[] = {0, 1, 0, -1};

	for(auto query: q) { //we will calculate for each query
		int x = query[0];
		int y = query[1];

		//already land because you marked it in the first query.
		if(mat[x][y]==1) { //if this is a repeated query
			ans.push_back(count);
			continue; //prevents double-counting the same cell as a new island.
		}

		mat[x][y]=1; //mark this query as an island
		count++; //increase the count of islands found till now

		int nodeNo = (x*m)+y; //get the node number for current cell

		for(int k=0; k<4; k++) { //check in all four directions
			int nr = x+dr[k];
			int nc = y+dc[k];
			//if in any adjacent direction there is an island that 
			//has been marked because of any previous query
			if(nr>=0 && nc>=0 && nr<n && nc<m && mat[nr][nc]==1) {
				int adjNodeNo = (nr*m)+nc; //get the node number of the adj cell
				int p1 = ds.findUParent(nodeNo); //get the ulp pf curr node
				int p2 = ds.findUParent(adjNodeNo); //get the ulp of adj node
				if(p1 != p2) { //if they don't belong to the same component
					ds.unionBySize(nodeNo, adjNodeNo); //connect the components
					count--; //since we increased the count when we found a 1
				}
			}
		}
		ans.push_back(count); //push the count till the current query
	}

	return ans;
}