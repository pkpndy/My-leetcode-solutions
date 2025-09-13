vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dist(n+1, 1e8); //mark 
    dist[src] = 0; //distance taken to reach source node will be zero
    //we dont need adjacency list or adjacency matrix
    for(int i=1; i<=n-1; i++) { //we relax all the edges n-1 times where n is the number of nodes
        for(auto it: edges) {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            //add check for max first so that adding wt doesn't wraps up the integer value
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) { 
                dist[v] = dist[u] + wt; //here we are realxing
            }
        }
    }

    return dist;
}