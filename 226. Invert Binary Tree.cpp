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
private:
    void invert(TreeNode* node) {
        if(node == nullptr) return;

        //go to all the nodes and swap its left and right
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
        invert(node->left); //now do the same for its left node
        //backtrack and do the same for its right node
        invert(node->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};