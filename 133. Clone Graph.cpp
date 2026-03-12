/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, Node* cloneNode, unordered_map<Node*, Node*>& mpp) {
        for(Node* originalNeighbor: node->neighbors) { //present node ke saare neighbors ko traverse krenge
            if(mpp.find(originalNeighbor)==mpp.end()) { // agar iss node ka already deep clone nhi bna hai toh
                Node* clonedNeighbor = new Node(originalNeighbor->val); //pehle toh original node ke neighbor ka clone bnao
                mpp[originalNeighbor]=clonedNeighbor; //map mein daalo ki ye traverse kr liye
                cloneNode->neighbors.push_back(clonedNeighbor); //cloned neighbor ko current node ke neighbors mein add kr do
                dfs(originalNeighbor, clonedNeighbor, mpp); //neighbor ke liye call kr do
            } else {
                // present node ke clone ka neighbor already traversed hai toh bs present 
                // cloneNode ke neighbor mein originalNeighbor nhi originalNeighbor ka cloned node jayega 
                cloneNode->neighbors.push_back(mpp[originalNeighbor]);
            }
        }
        return;
    }

    Node* cloneGraph(Node* node) {
        if(!node)   return node;
        unordered_map<Node*, Node*> mpp;

        Node* cloneNode = new Node(node->val);

        mpp[node]=cloneNode;
        dfs(node, cloneNode, mpp);

        return cloneNode;
    }
};