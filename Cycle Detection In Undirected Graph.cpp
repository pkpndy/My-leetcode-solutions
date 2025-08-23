#include<queue>

//bfs traversal
bool detectCycle(int src, vector<int> adj[], vector<int>& vis)
{
    vis[src] = 1; //mark the node as visited
    queue<pair<int, int>> q; //create a queue for this graph component
    q.push({src, -1}); //start by pushing the first node and no parent hence -1 as parent

    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjacentNode: adj[node]) { //this will traverse all the adjacent nodes of a node
            if(!vis[adjacentNode]) { //if the adjacent node is not visited
                vis[adjacentNode]=1; //mark it as visited 
                q.push({adjacentNode, node}); //push it into the queue for traversal
            }
            //since we already checked if node is not visited, then if it came to this check means its visited
            else if(adjacentNode != parent) { //if this node is visited but its not the parent node
                return true; //then someone else has visited the node, we found a cycle return true
            }
        }
    }
    return false; //traversed all the adjacent nodes for this graph component, and found no cycle
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //we are using adjacency list, that is an array of vectors, 
    //which is an array having vector<int> as its data type
    vector<int> adj[n+1]; //since the vertices are 1 based indexing

    for(int i=0; i<m; i++) { //traversing the edge array
        int u, v;
        u = edges[i][0];
        v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u); //since its an undirected graph, hence both will be pushed
    }

    vector<int> vis(n+1, 0); //visited array will also have size n+1, bcoz of i based vertices

    for(int i=1; i<=n; i++) { //traversing all the vertices, we use this bcoz of connected components graph
        if(!vis[i]) { //if not visited
            if(detectCycle(i, adj, vis)==true) {
                return "Yes";
            }
        }
    }

    return "No";
}

//dfs traversal
bool detectCycle(pair<int, int> np, vector<int> adj[], vector<int>& vis)
{
    vis[np.first] = 1;
    int node = np.first;
    int parent = np.second;
    for(auto adjacentNode: adj[node]) {
        if(!vis[adjacentNode]) {
            vis[adjacentNode]=1;
            //this if is useful when at any step true is returned then we don't need to make further calls
            if(detectCycle({adjacentNode, node}, adj, vis)) {
                return true;
            }
        }
        else if(adjacentNode != parent) {
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adj[n+1];
    for(int i=0; i<m; i++) {
        int u, v;
        u = edges[i][0];
        v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n+1, 0);
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            pair<int, int> np = {i, -1};
            if(detectCycle(np, adj, vis)==true) {
                return "Yes";
            }
        }
    }

    return "No";
}
