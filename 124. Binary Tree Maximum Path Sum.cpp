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
    int maxi=INT_MIN;

    int gms(TreeNode* node) {
        if(!node)   return 0;

        int l = gms(node->left); //solve the left subtree
        int r = gms(node->right); //solve the right subtree

        int koi_ek_accha = node->val + max(l, r); //right ya left subtree mein se ek hi use hoga max k liye
        int neeche_hi_mil_gya = node->val + l + r; //neeche hi koi subtree max de rha hai
        int only_root_accha = node->val; //sirf root akela hi max answer de rha hai
    
        maxi = max({maxi, koi_ek_accha, neeche_hi_mil_gya, only_root_accha}); //calculate max of all cases

        // return toh hm path kr rhe toh ya toh sirf root ya left ya right subtree ko include krke koi path
        return max(koi_ek_accha, only_root_accha);
    }

    int maxPathSum(TreeNode* root) {
        if(!root || (!root->left && !root->right))  return root->val;
        gms(root);
        return maxi;
    }
};