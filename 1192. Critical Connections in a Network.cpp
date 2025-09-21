class Solution {
private:
    int timer=1;
public:
// The Memory Limit Exceeded (MLE) isn’t because Tarjan’s algorithm itself is heavy—it’s linear in V+E. 
// The problem is in how you’re passing parameters.

// Every recursive call copies the entire adjacency list. adjList, hence pass it by reference
// That’s O(V+E) memory per recursion call → easily blows memory.
    void dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adjList, 
    int tin[], int low[], vector<vector<int>>& bridges) {
        vis[node]=1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it: adjList[node]) {
            if(it == parent)    continue;
            if(vis[it] == 0) {
                dfs(it, node, vis, adjList, tin, low, bridges);
                low[node] = min(low[it], low[node]);
                if(low[it] > tin[node]) {
                    bridges.push_back({node, it});
                }
            } else {
                low[node] = min(low[it], low[node]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjList(n);
        for(auto it: connections) {
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adjList, tin, low, bridges);
        return bridges;
    }
};