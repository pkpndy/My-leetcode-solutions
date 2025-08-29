class Solution {
public:
    //passing adjList by value means a copy of the whole graph is made every time dfs() is called 
    // this gives O(N²) overhead per call, leading to TLE, hence pass by reference
    bool dfs(int node, vector<vector<int>>& adjList, vector<int>& vis) {
        vis[node]=1; //mark this node as visited
        for(int adj: adjList[node]) {
            //reached the same node again, in the current path(current recursion stack or current dfs call)
            //because if we reached this same node from different path it would have had vis[adj]=2
            if(vis[adj]==1)    return false;
            else if(vis[adj]==0) {
                if(dfs(adj, adjList, vis) == false)  return false;
            }
        }
        vis[node]=2; //fully explored, no cycles through this node or on this path
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adjList(n);
        //since edges are given on the connections of each node
        for(auto it: prerequisites) {
            int u = it[0];
            int v = it[1];
            adjList[v].push_back(u); //To take course u, you must first take course v
        }
        bool result;
        vector<int> vis(n, 0); //0 means unvisited
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                if(!dfs(i, adjList, vis)) return false; 
            }
        }
        return true;
    }
};