class Solution {
  public:
    void dfs(int node, vector<int>& result, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node]=1;
        result.push_back(node);
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(it, result, vis, adj);
            }
        }
    }  
  
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> result, vis(n, 0);
        dfs(0, result, vis, adj);
        return result;
    }
};