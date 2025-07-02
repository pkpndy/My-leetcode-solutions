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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
private:
    int height(TreeNode* node, int& diameter) {
        if(node == nullptr) return 0; //if reached nullptr 

        int lh = height(node->left, diameter); //height of left subtree
        int rh = height(node->right, diameter); //height of right subtree
        diameter = max(diameter, lh+rh); //calculating max diameter with each node as turning points
        return 1 + max(lh, rh); //max height from on current node return
    }
};