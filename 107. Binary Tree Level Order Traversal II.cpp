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

 #include <algorithm>
class Solution {
public:
    void lob(vector<vector<int>>& result, vector<int> ds, TreeNode* node, queue<TreeNode*>& q) {
        if(q.empty()) return; //the recursion will end when we have processed all the nodes

        int n = q.size();
        ds.clear(); //we want the ds to be empty after each level

        while(n>0) {
            TreeNode* currNode = q.front();  q.pop();
            ds.push_back(currNode->val);
            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
            n--;
        }

        result.push_back(ds);
        lob(result, ds, node, q); //keep on calling it will chose the next node automatically
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)  return {};
        if((!root->left && !root->right))   return {{root->val}};

        queue<TreeNode*> q; //queue is used for pushing the children of each node and then popping to do operations on them
        vector<vector<int>> result;
        vector<int> ds;

        q.push(root);
        lob(result, ds, root, q);
        reverse(result.begin(), result.end());

        return result;
    }
};