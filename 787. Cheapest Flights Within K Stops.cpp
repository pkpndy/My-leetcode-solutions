class Solution {
public:
    //dijkastra's algorithm won't work here bcoz there are two dependables for answer not one
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjList(n);
        for(auto adj: flights) {
            int u = adj[0];
            int v = adj[1];
            int price = adj[2];
            adjList[u].push_back({v, price}); //u->v, price
        }
        vector<int> minCost(n, INT_MAX); //store the minimum price for each node
        queue<pair<pair<int, int>, int>> q; //use simple queue to store the {{price, stops}, node}
        minCost[src] = 0; //min price to reach source node
        q.push({{0, 0}, src}); //{{price, stops}, node}

        while(!q.empty()) {
            auto [price, stops] = q.front().first;
            int node = q.front().second;
            q.pop();

            if(stops>k) continue; //dont take this path as the stops count has exceeded k

            for(auto adj : adjList[node]) {
                int adjNode = adj.first;
                int totalCost = price + adj.second; //total cost to reach this city (edge weight + cost till prev node)
                //only consider if the cost to reach this node is less than any time earlier
                if (totalCost < minCost[adjNode]) {
                    minCost[adjNode] = totalCost; //store the minimum cost
                    q.push({{totalCost, stops + 1}, adjNode}); //push this into the queue
                }
            }
        }

        return minCost[dst] == INT_MAX ? -1 : minCost[dst];

    }
};