class Solution {
private:
    bool checkBST(TreeNode* node, long minV, long maxV) {
        //if reached till the end return true
        if(node == nullptr)   return true;
        
        //on the left subtree the node->val shouldn't be >= maxValue found till now
        //on the right subtree the node->val shouldn't be <= minValue found till now
        if(node->val >= maxV || node->val <= minV)  return false;
        
        //pass on the minVal and maxVal for left subtree and right subtree
        return (checkBST(node->left, minV, node->val) && checkBST(node->right, node->val, maxV));
    }
public:
    bool isValidBST(TreeNode* root) {
        //we will keep a range for each node
        return checkBST(root, LONG_MIN, LONG_MAX);
    }
};