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
    void inorder(TreeNode* node, vector<int>& iot) {
        if(node == nullptr) return; //if we reached a nullptr

        inorder(node->left, iot); //left
        iot.push_back(node->val); //node->val
        inorder(node->right, iot); //right
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> iot; //data structure to store the inorder traversal
        if(root == nullptr) return iot; //edge case

        inorder(root, iot);

        return iot;
    }
};