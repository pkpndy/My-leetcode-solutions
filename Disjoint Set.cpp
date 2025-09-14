#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank, size;
    public:
        DisjointSet(int n) {
            rank.resize(n+1, 0); //n+1 to accomodate the nodes if start from 1
            size.resize(n+1, 1); //n+1 to accomodate the nodes if start from 1
            parent.resize(n+1);
            for(int i=0; i<=n; i++) {
                parent[i] = i; //in the start every node is the parent of itself
            }
        }

        int findUParent(int node) {
            if(node == parent[node]) //if it points to itself finally, then its the ultimate parent
                return node;
            //this will find parent of the node and
            //also do a path compression by attaching the node to the ultimate parent directly
            return parent[node] = findUParent(parent[node]);
        }

        void unionByRank(int u, int v) {
            //find the parent of both the nodes
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            //check if the belong to the same component (if they have same ultimate parent)
            if(ulp_u == ulp_v)  return; //if the belong to the same component, do nothing
            //if they dont, then check the size of both and attach the smaller one to the larger one
            if(rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_u] > rank[ulp_v]) {
                parent[ulp_v] = ulp_u;
            }
            else { //if the ranks are equal
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u, int v) {
            //find parent of both the nodes
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            //check if the belong to the same component (if they have same ultimate parent)
            if(ulp_u == ulp_v)  return; //if the belong to the same component, do nothing
            //if they dont, then check the size of both and attach the smaller one to the larger one
            if(size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_v];
            }
            else { //this will take equal and size[ulp_u] > size[ulp_v] into consideration
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

int main() {
    DisjointSet ds(7);
    //we always create a mst using disjoint set 
    //which checks if the nodes already belong to the MST
    //if not then connects them according to size or rank

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // ds.unionByRank(1, 2);
    // ds.unionByRank(2, 3);
    // ds.unionByRank(4, 5);
    // ds.unionByRank(6, 7);
    // ds.unionByRank(5, 6);
    if(ds.findUParent(3) == ds.findUParent(7)) {
        cout<<"same"<<endl;
    } else {
        cout<<"Not same"<<endl;
    }
    ds.unionBySize(3, 7);
    // ds.unionByRank(3, 7);
    if(ds.findUParent(3) == ds.findUParent(7)) {
        cout<<"same"<<endl;
    } else {
        cout<<"Not same"<<endl;
    }
}