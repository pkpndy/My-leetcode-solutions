class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        queue<int> q;

        for(int start=0; start<n; start++) { //always think of connected components
            if(color[start] != -1)  continue;
            q.push(start);
            color[start] = 0;
            while(!q.empty()) {
                int node = q.front();   q.pop();
                for(int adj: graph[node]) {
                    if(color[adj] == -1) {
                        color[adj] = !color[node];
                        q.push(adj);
                    }
                    else {
                        if(color[adj] == color[node]) {
                            return false;
                        }
                    }
                }
            }
            
        }
        return true;
    }

    //dfs solution
    bool dfs(int node, vector<int>& color, vector<vector<int>>& graph) {
        for(int adj : graph[node]) {
            if(color[adj] == -1) {
                color[adj] = !color[node];
                if(dfs(adj, color, graph) == false) return false;
            } else {
                if(color[adj] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        bool res;

        for(int start=0; start<n; start++) { //always think of connected components
            if(color[start] != -1)  continue;
            color[start] = 0;
            res = dfs(start, color, graph);
            if(!res)    return false;
        }
        return true;
    }
};