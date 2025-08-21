class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& ic) {
        vis[node]=1; //mark the node visited
        for(int i=0; i<ic[node].size(); i++) { //check for all nodes in its vector
            if(!vis[i] && ic[node][i] == 1) { //if the node ain't visited and is connected to this node 
                //this call will mark the connected node as visited and also mark its connected nodes as visited
                dfs(i, vis, ic);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); //number of nodes
        int result=0;
        vector<int> vis(n, 0); //doesn't matter the numbering, the vector is 0 indexed
        for(int i=0; i<n; i++) { //check for all nodes 
            if(!vis[i]) { //if the node is not visited
                result++; //we got a new province, as we will mark all the connected nodes as visited
                dfs(i, vis, isConnected); //send the node with visited array
            }
        }
        return result;
    }
};