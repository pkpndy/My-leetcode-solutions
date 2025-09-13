#include<queue>

//this is prims algorithm
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  vector<vector<pair<int, int>>> adjList(n);
  for(auto adj: edges) {
    int u = adj[0];
    int v = adj[1];
    int wt = adj[2];
    adjList[u].push_back({wt, v});
    adjList[v].push_back({wt, u}); //undirected graph
  }

  vector<int> vis(n, 0);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //we take out the minimum weight each time
  pq.push({0, 0}); //{wt, node}

  int sum=0;
  while(!pq.empty()) {
    auto [wt, node] = pq.top(); pq.pop();
    if(vis[node]) continue; //this means we already have that node with smaller weight due to priority queue
    vis[node]=1;
    sum += wt;
    for(auto adj: adjList[node]) {
      int adjWt = adj.first;
      int adjNode = adj.second;
      if(!vis[adjNode]) {
        pq.push({adjWt, adjNode});
      }
    }
  }

  return sum;
}