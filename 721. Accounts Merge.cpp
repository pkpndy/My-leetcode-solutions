class DisjointSet {
    vector<int> parent, rank;
    public:
        DisjointSet(int n) {
            rank.resize(n, 0);
            parent.resize(n);
            for(int i=0; i<n; i++) {
                parent[i]=i;
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
            }else if(rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
            }else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size(); //each first word of each vector<string> will be treated as node
        DisjointSet ds(n); //we create a disjoint set out of these
        unordered_map<string, int> mapMailNode; //we create a map of [mail->node]
        for(int i=0; i<n; i++) {
            //we leave the first word of each vector, as they will be treated a nodes
            for(int j=1; j<accounts[i].size(); j++) {
                string mail = accounts[i][j]; //take the mail
                if(mapMailNode.find(mail) == mapMailNode.end()) { //if the mail is not already present
                    mapMailNode[mail] = i; //simply add it to the map with its node
                } else { //if already present
                //connect the node of this mail with the node of the already present mail
                    ds.unionByRank(i, mapMailNode[mail]);
                }
            }
        }

        vector<string> mergedMail[n]; //an array of size n, each element is vector<string>
        //vector<string> mergedMail(n); //a single vector of strings of size n

        for(auto it: mapMailNode) { //traverse the map
            string mail = it.first; //mails are at the first
            //get the node this is connected to, we take the ulti parent because many were connected
            int node = ds.findUParent(it.second);
            mergedMail[node].push_back(mail); //push the mails to their respective node
        }

        //create the answer out of the merged mails
        vector<vector<string>> ans;
        for(int i=0; i<n; i++) {
            //skip the vectors that don't have any element as it might give error
            if(mergedMail[i].size() == 0)   continue;
            sort(mergedMail[i].begin(), mergedMail[i].end()); //sort each vector
            vector<string> temp;
            temp.push_back(accounts[i][0]); //since the first words were converted to nodes earlier
            for(auto it: mergedMail[i]) {
                temp.push_back(it); //then push the mails
            }
            ans.push_back(temp);
        }

        return ans;
    }
};