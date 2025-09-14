class DisjointSet {
    vector<int> parent, rank;
    public:
        DisjointSet(int n) {
            rank.resize(n, 0);
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

        void unionByRank(int u, int v) {
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            if(ulp_u == ulp_v)  return;
            if(rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            } else if(rank[ulp_u] > rank[ulp_v]) {
                parent[ulp_v] = ulp_u;
            } else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        int giveParents() {
            int noOfParents=0;
            for(int i=0; i<parent.size(); i++) {
                if(parent[i]==i)    noOfParents++;
            }
            return noOfParents;
        }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extraWire = 0; //count the number of extra wires
        DisjointSet  ds(n); //we create n nodes each represents an independent computer initially
        for(auto conn: connections) {
            int u = conn[0];
            int v = conn[1];
            if(ds.findUParent(u) == ds.findUParent(v)) { //check if two computers belong to the same network
                extraWire++; //if two computers are already connected, then another connection means its extra
            }
            else {
                ds.unionByRank(u, v); //if they don't belong then connect them
            }
        }
        //the nodes that point parents to themselves are still disconnected
        int disconnectedComputers = ds.giveParents();
        //if we have the wires equal to or more than the left out computers then we will use
        //number of disconnected computers of operations to connect them to the network
        if(extraWire >= disconnectedComputers - 1) return disconnectedComputers-1;
        return -1; //or else we can't connect them
    }
};