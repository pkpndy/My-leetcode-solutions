class Solution {
public:
    bool dfs(int node, vector<int>& result, vector<vector<int>>& adjList, vector<int>& vis) {
        if(vis[node] == 1)  return false; //found a cycle
        if(vis[node] == 2)  return true; //node already processed

        vis[node]=1; //mark node as visited
        for(int adj: adjList[node]) {
            if(!dfs(adj, result, adjList, vis)) return false;
        }
        vis[node]=2; //mark node as processed
        //pushing starts from the last node as it starts from the last node that has no dependency
        result.push_back(node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> vis(n, 0);
        vector<vector<int>> adjList(n);
        for(auto adj: prerequisites) {
            int u = adj[0];
            int v = adj[1];
            adjList[v].push_back(u);
        }
        vector<int> result; 
        for(int i=0; i<n; i++) {
            if(!vis[i]) { //we do this for connected components
                if(!dfs(i, result, adjList, vis)) {
                    return {};
                }
            }
        }
        reverse(result.begin(), result.end()); //reverse the result as we made a list from last node
        return result;
    }

    //this is a topological sort(DAG) related problem
    //kahn's algorithm (bfs)
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adjList(n);
        vector<int> indegree(n, 0);
        vector<int> result;
        for(auto adj : prerequisites) {
            int u = adj[0];
            int v = adj[1];
            adjList[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++)  if(indegree[i] == 0)    q.push(i);

        while(!q.empty()) {
            int node = q.front(); q.pop();
            result.push_back(node);
            for(int adj : adjList[node]) {
                indegree[adj]--;
                if(indegree[adj]==0)    q.push(adj);
            }
        }
        if(result.size() != n)  return {};
        return result;
    }
};