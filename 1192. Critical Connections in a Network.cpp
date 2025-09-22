class Solution {
private:
    int timer=1;
public:
// Every recursive call copies the entire adjacency list, if you pass it by value.
// That’s O(V+E) memory per recursion call → easily blows memory.
    void dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adjList, 
    int tin[], int low[], vector<vector<int>>& bridges) {
        vis[node]=1;
        tin[node] = low[node] = timer; //on reaching a node we update the time taken and lowest time
        timer++; //increase the timer
        for(auto it: adjList[node]) { //explore all the adjacent nodes
            if(it == parent)    continue; //if the adjacent node is parent then ignore
            if(vis[it] == 0) { //if the adjacent node is not visited
                dfs(it, node, vis, adjList, tin, low, bridges); //make the dfs call for this node
                low[node] = min(low[it], low[node]); //we store the lowest time to reach this node
                
                //if there was any other path to this adjacent node(it), then the lowest time taken 
                // to reach it would have been same or less then tin[node],
                // if its greater then the only way to reach it is through our current node
                if(low[it] > tin[node]) {
                    bridges.push_back({node, it}); //then its a bridge
                }
            } else {
                //even if the adjacent node is already visited we still store the lowest time to reach 
                low[node] = min(low[it], low[node]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjList(n);
        for(auto it: connections) { //we first create a graph out of the edges
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u); //since it is an undirected graph
        }

        vector<int> vis(n, 0); //visited array, since we are going to do dfs traversal
        int tin[n]; //time/steps taken to reach a node (time of insertion into the call stack)
        int low[n]; //lowest time of all adjacent nodes except the parent
        vector<vector<int>> bridges; //store the final bridges found
        dfs(0, -1, vis, adjList, tin, low, bridges); //first node and its parent
        return bridges;
    }
};