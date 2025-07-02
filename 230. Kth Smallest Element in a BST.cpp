class Solution {
private:
    void iot(TreeNode* node, vector<int>& ans) {
        if(node==nullptr)   return;

        iot(node->left, ans);
        ans.push_back(node->val);  
        iot(node->right, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) return 0;

        vector<int> ans; //we store the sorted output in an array 
        iot(root, ans); //inorder traversal of a BST will give sorted output
        return ans[k-1]; //then give the number at k-1 (since it is 1-indexed)
    }
};