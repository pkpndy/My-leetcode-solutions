#include<queue>

//we are using kahn's algorithm here, in which we keep the track of indegree 0 and push it to queue
//its slight modification to bfs algorithm
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<vector<int>> adjList(n+1); //n+1 coz the nodes were starting from 1
  vector<int> indegree(n+1, 0); //for storing the indegree of each node
  for(auto adj: edges) { //creating adjacency list from the edges
    int u = adj.first;
    int v = adj.second;
    adjList[u].push_back(v);
    //indegree means number of edges coming inwards to this node
    indegree[v]++; //also calculating the indegree of each node 
  }

  queue<int> q; //for bfs like traversal
  //pushing the nodes having indegree 0 into the queue
  for(int i=1; i<=n; i++) if(indegree[i]==0)  q.push(i);

  // counting the number of nodes processed, since if there was a cycle there will come a point when no node
  // will have indegree 0 and the processsing of nodes will stop and not all node will get processed
  int processedNodes=0;
  while(!q.empty()) {
    int node = q.front(); q.pop();
    processedNodes++; //increase the number of processed nodes
    for(int adj: adjList[node]) { //process the node
      indegree[adj]--; //decrease the indegree of the connected node, since we are removing current node
      if(indegree[adj]==0)  q.push(adj); //if indegree became 0 push it to the queue
    }
  }
  if(processedNodes == n)  return false; //if all nodes get processed then it means no cycle present
  return true;
}

//dfs approach
bool dfs(int node, vector<int>& vis, vector<vector<int>>& adjList) {
  vis[node] = 1;
  for(int adj : adjList[node]) {
    if(vis[adj]==1) return true;
    if(!vis[adj]) {
      if(dfs(adj, vis, adjList)) return true;
    }
  }
    vis[node] = 2;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<vector<int>> adjList(n+1);
  vector<int> vis(n+1, 0);
  for(auto adj: edges) {
    int u = adj.first;
    int v = adj.second;
    adjList[u].push_back(v);
  }

  for(int i=1; i<=n; i++) {
    if(!vis[i]) {
      if(dfs(i, vis, adjList)) {
        return true;
      }
    }
  }
  return false;
}