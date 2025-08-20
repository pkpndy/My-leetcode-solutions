class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> result;
        vector<int> vis(n, 0);
        
        queue<int> q;
        q.push(0); //add the initial node
        vis[0]=1; //mark it as visited so it doesn't get repeated when coming back
        
        while(!q.empty()) {
            int node = q.front();
            result.push_back(node);
            q.pop();
            for(auto it: adj[node]) {
                if(!vis[it]) {
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        
        return result;
    }
};