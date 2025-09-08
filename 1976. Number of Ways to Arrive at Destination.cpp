class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7; //The number of paths can be large. You typically take modulo 1e9 + 7
        vector<vector<pair<int, int>>> adjList(n);
        for(auto adj : roads) {
            int u = adj[0];
            int v = adj[1];
            int dist = adj[2];
            adjList[u].push_back({dist, v});
            adjList[v].push_back({dist, u});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq; //{dist, node}
        vector<long long> minDist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        pq.push({0, 0});
        ways[0]=1;
        minDist[0]=0;

        while(!pq.empty()) {
            auto [dist, node] = pq.top();   pq.pop();
            if (dist > minDist[node]) continue;
            for(auto adj: adjList[node]) {
                int adjNodeDist = adj.first;
                int adjNode = adj.second;
                long long totalDist = dist + adjNodeDist;
                if(totalDist < minDist[adjNode]) {
                    minDist[adjNode] = totalDist;
                    pq.push({totalDist, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(totalDist == minDist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1];
    }
};