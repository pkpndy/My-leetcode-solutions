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
    void preorder(TreeNode* node, vector<int>& pot) {
        if(node == nullptr) return; //if we reached a nullptr

        pot.push_back(node->val); //node->val
        preorder(node->left, pot); //left
        preorder(node->right, pot); //right
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pot; //data structure to store the preorder traversal
        if(root == nullptr) return pot; //edge case

        preorder(root, pot); 

        return pot;
    }
};