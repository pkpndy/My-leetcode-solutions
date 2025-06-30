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
    int giveHeight(TreeNode* node) {
        if(node == nullptr) return 0; //if the node reaches nullptr

        //if at any subtree the height difference becomes greater than 1
        //then no need to check further
        int lh = giveHeight(node->left);
        if(lh == -1)    return -1;
        int rh = giveHeight(node->right);
        if(rh == -1)    return -1;

        if (abs(lh - rh) > 1) return -1; 

        return 1+max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        return giveHeight(root) != -1; //if it returns some height then true 
    }
};