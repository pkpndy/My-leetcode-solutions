/*
You have been given an undirected graph of ‘V’ vertices (labeled 0,1,..., V-1) and ‘E’ edges.
Each edge connecting two nodes (‘X’,’Y’) will have a weight denoting the distance between node ‘X’ and node ‘Y’.

Your task is to find the shortest path distance from the source node, which is the node labeled as 0, to all vertices given in the graph.

Example:

Input:
4 5
0 1 5
0 2 8
1 2 9
1 3 2
2 3 6
*/

#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<vector<pair<int, int>>> adjlist(vertices); //create adjacency list
    for(auto adj : vec) { //iterate the vector having edges
        int u = adj[0];
        int v = adj[1];
        int dist = adj[2];
        adjlist[u].push_back({dist, v}); //we will store {distance, adjNode}
        adjlist[v].push_back({dist, u}); //do other way too, undirected graph
    }

    vector<int> minDist(vertices, INT_MAX); //for storing the minimum distances
    
    //pq<data_type, container, comparator>; 
    //data_type : type of elements stores in the pq
    //container : underlying container that stores the elements, 
    //            must be a random access container
    //comparator : priority_queue default behaviour is max heap, but we want min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    pq.push({0, source}); //we start {distance for sourceNode, sourceNode}
    minDist[source] = 0; //mark the distance taken for reaching sourceNode

    while(!pq.empty()) {
        int u = pq.top().second; //pick the currNode
        int dist = pq.top().first; //pick the minimum distance taken to reach currNode
        pq.pop();
        for(auto adj : adjlist[u]) { //iterate the currNode
            int adjDist = adj.first; //distance between currNode and adjNode
            int adjNode = adj.second; //the adjacent Node
            //if the earlier taken path has more distance than coming from current node
            if(minDist[adjNode] > adjDist+dist) {
                minDist[adjNode] = adjDist+dist; //store this current path distance
                //we store the distance first bcoz we want ascending order of distance,
                //then if distance same then ascending order of node
                pq.push({minDist[adjNode], adjNode});
            }
        }
    }

    return minDist;
}
