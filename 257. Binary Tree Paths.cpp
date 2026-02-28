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
    void gms(TreeNode* node, string str, vector<string>& result) {
        if(!node)   return;

        str += "->" + to_string(node->val);

        if(!node->left && !node->right) { //we only want to push when the node is a leaf node
            result.push_back(str);
            return;
        }

        if(node->left)  gms(node->left, str, result);
        if(node->right)  gms(node->right, str, result);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root || (!root->left && !root->right))  return {to_string(root->val)};

        TreeNode* it = root;
        vector<string> result;
        string str;
        str.append(to_string(it->val));
        gms(it->left, str, result);
        gms(it->right, str, result);
        return result;
    }
};