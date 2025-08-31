/*
Problem statement
The city of Ninjaland is analogous to the unweighted graph. 
The city has ‘N’ houses numbered from 1 to ‘N’ respectively and are connected by M bidirectional roads.
If a road is connecting two houses ‘X’ and ‘Y’ which means you can go from ‘X’ to ‘Y’ or ‘Y’ to ‘X’. 
It is guaranteed that you can reach any house from any other house via some combination of roads. 
Two houses are directly connected by at max one road.

A path between house ‘S’ to house ‘T’ is defined as a sequence of vertices from ‘S’ to ‘T’. 
Where starting house is ‘S’ and the ending house is ‘T’ and there is a road connecting two consecutive houses. 
Basically, the path looks like this: (S , h1 , h2 , h3 , ... T). you have to find the shortest path from ‘S’ to ‘T’.

For example
In the below map of Ninjaland let say you want to go from S=1 to T=8, the shortest path is (1, 3, 8). 
You can also go from S=1 to T=8  via (1, 2, 5, 8)  or (1, 4, 6, 7, 8) but these paths are not shortest.
*/

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	vector<vector<int>> adjList(n+1);
	for(int i=0; i<m; i++) {
		int u = edges[i].first;
		int v = edges[i].second;
		//since it is an undirected graph we store both directions
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	queue<int> q;
	q.push(s); //push the starting node to start the traversal from there
	vector<int> minDistance(n+1, 1e9); //store the min distance to reach that node
	vector<int> parent(n+1, -1); //store the parent of each node
	minDistance[s] = 0; //the min distance to reach the starting node will be 0

	while(!q.empty()) {
		int node = q.front();
		int currnodeDis = minDistance[node]; //min distance to reach current node
		q.pop();
		for(int adj : adjList[node]) {
			//only calculate if we get distance less than earlier
			if(currnodeDis + 1 < minDistance[adj]) {
				minDistance[adj] = currnodeDis + 1;
				parent[adj] = node; //store the parent of the current node
				q.push(adj);
			}
		}
	}

	vector<int> path;
	//start from the terminal node, till parent node that has parent -1
	//each time go to the parent node of current node
	for(int i = t; i != -1; i = parent[i]) {
		path.push_back(i);
	}

	reverse(path.begin(), path.end()); //since we started from the terminal node
	return path;
}
