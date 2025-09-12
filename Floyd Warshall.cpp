int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    //we fill the cost matrix with max value 1e9 bcoz
    //INT_MAX + anything wraps around and gives the number from starting
    vector<vector<int>> cost(n+1, vector<int> (n+1, 1e9));
    for(int i=1; i<=n; i++) {
        cost[i][i]=0; //cost[i][i]=0 as the min distance to reach itself will be 0
    }
    for(auto adj: edges) {
        int u = adj[0];
        int v = adj[1];
        int wt = adj[2];
        cost[u][v] = wt;
    }

    for(int via=1; via<=n; via++) { //we try going via all the nodes
        for(int i=1; i<=n; i++) { //iteration for u
            for(int j=1; j<=n; j++) { //iteration for v
                //if any of them is maximum adding something might wrap around and
                //give some small number, also adding max to anything is already large
                if (cost[i][via] == 1e9 || cost[via][j] == 1e9) continue;
                
                //we take minimum of the already existing path cost and new cost
                cost[i][j] = min(cost[i][j], cost[i][via]+cost[via][j]);
            }
        }
    }

    return cost[src][dest]; 
}