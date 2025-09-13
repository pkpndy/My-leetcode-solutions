class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7; //The number of wayss can be large. You typically take modulo 1e9 + 7
        vector<vector<pair<int, int>>> adjList(n);
        for(auto adj : roads) {
            int u = adj[0];
            int v = adj[1];
            int time = adj[2];
            adjList[u].push_back({time, v});
            adjList[v].push_back({time, u}); //since it is undirected graph
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq; //{time, node}
        vector<long long> minTime(n, LLONG_MAX); // to store the minimum time for each node
        vector<int> ways(n, 0); //to store the number of ways that give minimum time for each node
        pq.push({0, 0}); //start at the source node
        ways[0]=1; //number of ways to reach the soure node will be only 1
        minTime[0]=0; //time taken to reach the source node will be 0

        while(!pq.empty()) {
            auto [time, node] = pq.top();   pq.pop();
            if (time > minTime[node]) continue; //eliminates reprocessing of nodes, when a better ways is already present
            for(auto adj: adjList[node]) {
                int adjNodeTime = adj.first;
                int adjNode = adj.second;
                //taking long long because adding the times gives really large number
                long long totalTime = time + adjNodeTime;
                if(totalTime < minTime[adjNode]) { //if we found a better time
                    minTime[adjNode] = totalTime; //then we store this time
                    pq.push({totalTime, adjNode}); //push this better time and node
                    ways[adjNode] = ways[node]; //store this minimum time
                }
                else if(totalTime == minTime[adjNode]) { //if we the current ways is also giving minimum time
                    //then add the number of ways to reach both the number of eariler ways and the ways till current node
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1];
    }
};