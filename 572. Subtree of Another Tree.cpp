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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //if one of them is null and if both of them are same
        if(p == nullptr || q == nullptr)   return (p == q);

        //if both are not null and their values match, 
        //then check their left and right subtrees match
        if(p && q && p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }

        return false; //if none of the subtree matches
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == nullptr)  return true; //if subroot is null then it will be a subtree
        //since we already checked for subroot is null or not, 
        //now we check root is null or not
        if(root == nullptr) return false;

        //since we checked that both of them are non-empty
        //now check if both of them are same
        if(isSameTree(root, subRoot))   return true;

        //check if left subtree is same or right subtree is same
        //if any of them is same return true
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};