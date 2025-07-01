/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    /*
    This recursive solution takes O(N) space and O(H) time
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q) { //handling the edge case
            return nullptr;
        }

        if(p->val < root->val && q->val < root->val) { //case where both are smaller
            return lowestCommonAncestor(root->left, p, q);
        } else if(p->val > root->val && q->val > root->val) { //case where both are greater
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root; //case where both of them are either equal or greater or smaller
        }
    }

    /*
    This iterative solution takes O(1) space and O(H) time
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;

        while(curr) {
            if(p->val < curr->val && q->val < curr->val) {
                curr = curr->left;
            } else if(p->val > curr->val && q->val > curr->val) {
                curr = curr->right;
            } else {
                return curr;
            }
        }
        return nullptr;
    }
};