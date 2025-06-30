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
    void postorder(TreeNode* node, vector<int>& ptt) {
        if(node == nullptr) return; //if we reached a nullptr

        postorder(node->left, ptt); //left
        postorder(node->right, ptt); //right
        ptt.push_back(node->val); //node->val
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ptt; //data structure to store the inorder traversal
        if(root == nullptr) return ptt; //edge case

        postorder(root, ptt); 

        return ptt;
    }
};