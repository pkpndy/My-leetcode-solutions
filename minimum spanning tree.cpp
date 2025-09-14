#include<queue>

//this is prims algorithm, but this gives TLE
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

//this is kruskal's algorithm, that uses disjoint set, findUParent and union
#include<algorithm>

class DisjointSet {
  vector<int> parent, rank, size;
  public:
    DisjointSet(int n) {
      rank.resize(n+1, 0);
      size.resize(n+1, 1);
      parent.resize(n+1);
      for(int i=0; i<=n; i++) {
        parent[i] = i;
      }
    }

    int findUParent(int node) {
      if(node == parent[node])
        return node;
      return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v) {
      int ulp_u = findUParent(u);
      int ulp_v = findUParent(v);
      if(ulp_u == ulp_v)  return;
      if(rank[ulp_u] < rank[ulp_v]) {
        parent[ulp_u] = ulp_v;
      } else if (rank[ulp_u] > rank[ulp_v]) {
        parent[ulp_v] = ulp_u;
      } else {
        rank[ulp_u]++;
        parent[ulp_v] = ulp_u;
      }
    }
};

static bool compareEdges(const vector<int>& a, const vector<int>& b) {
  return a[2] < b[2]; //compare by weight
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  int minWt = 0;
  sort(edges.begin(), edges.end(), compareEdges); //we sort the edges by weight to get the smallest weights first

  DisjointSet ds(n); //then we create n nodes each as an independent component initially

  for(const auto edge: edges) {
    int u = edge[0], v = edge[1], wt = edge[2];
    if(ds.findUParent(u) != ds.findUParent(v)) { //if these two nodes don't belong to the same component
      minWt += wt; //then add the edge weight
      ds.unionByRank(u, v); //connect both the nodes
    }
  }

  return minWt;
}
