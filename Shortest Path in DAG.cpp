//the intution here is we start by sorting the nodes in topological order
//to we get nodes in dependent order
bool dfs(int node, vector<vector<pair<int, int>>>& adjList, vector<int>& vis, stack<int>& st)
{
    vis[node]=1;
    for(auto it : adjList[node]) {
        int v = it.first;
        if(vis[v]==1)   return false;
        if(vis[v]==0) {
            dfs(v, adjList, vis, st);
        }
    }
    vis[node]=2;
    st.push(node); //just like we store the number after the recursive call
    return true;
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    vector<vector<pair<int, int>>> adjList(n);
    vector<int> vis(n, 0);
    for(int i=0; i<m; i++) { //take special care of looping the edges(m) not nodes(n)
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adjList[u].push_back({v, wt});
    }

    stack<int> st; //stack will store the nodes in topological order
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            dfs(i, adjList, vis, st);
        }
    }

    vector<int> distance(n, 1e9);
    distance[0] = 0; //if no source node given then take 0 as source node
    while(!st.empty()) {
        int node = st.top(); st.pop();
        for(auto it : adjList[node]) {
            int v = it.first; //first is the connected node
            int wt = it.second; //second is the weight/distance of reaching it
            //if the distance on reaching v by coming through this path is less 
            //than the distance of any other path that came here earlier
            if(distance[node] + wt < distance[v]) { 
                distance[v] = distance[node] + wt; //store the minimal distance
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (distance[i] >= 1e9) { //if any of the node was unreachable
            distance[i] = -1;
        }
    }
    
    return distance;
}
