#include<stack>

void sortFinTime(int node, vector<int>& vis, stack<int>& st, vector<vector<int>>& adjList)
{
	vis[node]=1;
	for(auto it: adjList[node]) {
		if(!vis[it]) {
			sortFinTime(it, vis, st, adjList);
		}
	}
	st.push(node);
}

void dfs2(int node, vector<int>& vis, vector<int> adjRev[]) {
	vis[node]=1;
	for(auto it: adjRev[node]) {
		if(!vis[it]) {
			dfs2(it, vis, adjRev);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	//create the graph using edges
	vector<vector<int>> adjList(v);
	for(auto it: edges) {
		int u=it[0], w=it[1];
		adjList[u].push_back(w); //directed edges
	}

	//sort them according to finishing time using a stack
	vector<int> vis(v, 0);
	stack<int> st;
	for(int i=0; i<v; i++) {
		if(!vis[i]) {
			sortFinTime(i, vis, st, adjList);
		}
	}

	//reverse the edges, as this will isolate the strongly connected components
	vector<int> adjRev[v];
	for(int i=0; i<v; i++) {
		vis[i]=0;
		for(auto it: adjList[i]) {
			int u=i, w=it;
			adjRev[w].push_back(u);
		}
	}

	//do the dfs again using the sorted nodes in the stack
	int scc=0;
	while(!st.empty()) {
		int node = st.top();
		st.pop();
		if(!vis[node]) {
			scc++; //start of each new component will represent a new scc
			dfs2(node, vis, adjRev);
		}
	}

	return scc;
}