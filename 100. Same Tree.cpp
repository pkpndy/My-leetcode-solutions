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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //if any of them is nullptr then return if both are nullptr
        if(p == nullptr || q == nullptr)    return (p==q); 

        //we are doing preorder traversal tough we can do any traversal
        return (p->val == q->val) 
                && isSameTree(p->left, q->left)
                && isSameTree(p->right, q->right);
    }
};