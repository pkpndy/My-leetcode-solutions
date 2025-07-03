class Solution {
private:
    int maxPathSum(TreeNode* node, int& maxi) {
        if(node == nullptr) return 0;

        int left = max(0, maxPathSum(node->left, maxi)); //if the result is negative take 0 
        int right = max(0, maxPathSum(node->right, maxi)); //if result is negative take 0
        maxi = max(maxi, node->val + left + right); //just like height calculate max sum
        //return the sum of this node with its left and right subtree
        return node->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        //this problem is same as max height
        int maxi = INT_MIN; //taking INT_MIN because there are negative values also
        maxPathSum(root, maxi);
        return maxi;
    }
};