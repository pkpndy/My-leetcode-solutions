class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int thres = distanceThreshold;
        //the minDistance matrix for storing the minDist from each node to other node, via all nodes
        vector<vector<int>> minDist(n, vector<int> (n, INT_MAX));
        
        for(int i=0; i<n; i++)  minDist[i][i]=0; //the minDist to reach itself is 0
        
        for(auto it: edges) { //filling the matrix using the edges vector
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            minDist[u][v] = wt;
            minDist[v][u] = wt; //since it is undirected graph
        }

        for(int via=0; via<n; via++) { //via nodes
            for(int i=0; i<n; i++) { //from node
                for(int j=0; j<n; j++) { //to node
                    //skip the INT_MAX nodes as adding them will result in overflow or wrap]
                    if(minDist[i][via] == INT_MAX || minDist[via][j] == INT_MAX)    continue;

                    //compare if any earlier path gave min dist or the path via current is giving min dist
                    minDist[i][j] = min(minDist[i][j], minDist[i][via]+minDist[via][j]);
                }
            }
        }

        int city = 0; //to store the city that has min neighbours
        int minNeighCount = n+1; //take any max number, here we are taking one more than the total cities
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && minDist[i][j] <= thres) { //ignore if the count for the city itself
                    count++;
                }
            }
            if (count <= minNeighCount) { //if we found new min(or equal) neighbours count
                city = i; //store the city
                minNeighCount = count; //store the neighbours count
            }
        }

        return city; //return the city
    }
};