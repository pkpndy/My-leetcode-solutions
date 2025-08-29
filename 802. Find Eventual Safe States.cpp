class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<vector<int>>& graph) {
        vis[node]=1; //mark this node as visited
        for(auto adj: graph[node]) {
            //reached the same node again, in the current path(current recursion stack / current dfs call)
            //because if we reached this same node from different path it would have had vis[adj]=2
            if(vis[adj]==1) return false;
            else if(!vis[adj]) {
                if(!dfs(adj, vis, graph)) return false;
            }
        }
        vis[node]=2; //fully explored, no cycles through this node or on this path
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> result;
        for(int i=0; i<n; i++) {
            if(dfs(i, vis, graph)) { //if no cycles found for this i on all possible paths, then its safe
                result.push_back(i); //push this node
            }
        }
        return result;
    }
};