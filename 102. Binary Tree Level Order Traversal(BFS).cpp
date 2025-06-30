/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; //data structure to return the answer
        if(root == nullptr) return ans; //edge case

        queue<TreeNode*> q; //we will use queue to store the nodes at current level
        q.push(root); //start by pushing root
        while(!q.empty()) { //till queue is not empty(all nodes are not traversed)
            int qsize = q.size(); //we are storing the q size bcoz popping from the q will decrease its size
            vector<int> level; //each time new vector level will be created
            for(int i=0; i<qsize; i++) { 
                TreeNode* node = q.front();
                q.pop();
                if(node->left != nullptr)   q.push(node->left); //if left of curr node exists
                if(node->right != nullptr)   q.push(node->right); //if right of curr node exists
                level.push_back(node->val); //push the value to the current level nodes vector
            }
            ans.push_back(level); //push the current level 
        }
        return ans;
    }
};