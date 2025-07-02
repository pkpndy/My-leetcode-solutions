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
    int dfs(TreeNode* node, int maxVal) {
        if(!node)   return 0; //if node reaches nullptr

        int res = (node->val >= maxVal) ? 1 : 0; //count the good node if its >= maxVal
        maxVal = max(maxVal, node->val); //cal current max after this node
        res += dfs(node->left, maxVal); //call the function again for left subtree
        res += dfs(node->right, maxVal); //call the function again for the right subtree

        return res; //return result of current node
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};