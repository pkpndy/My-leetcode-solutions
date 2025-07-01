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
    //this recursive approach gives TC O(N) and SC O(H)
    void reversepdt(TreeNode* node, vector<int>& ans, int level) {
        if(node == nullptr) return;

        //whenever a new level is reached push the right most node as we go right first
        if(level == ans.size()) ans.push_back(node->val);
        reversepdt(node->right, ans, level+1); //go right
        reversepdt(node->left, ans, level+1); //then go left
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        //we are going to use reverse preorder (root, right, left)
        //if left side view is needed will will do preorder (root, left, right)
        vector<int> ans;
        reversepdt(root, ans, 0);
        return ans;
    }

    // this is the iterative approach TC O(N) and SC O(the breadth of the leaf nodes)
    /*
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)   return ans;

        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int qsize = q.size();
            for(int i=0; i<qsize; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (i == qsize - 1) {
                    ans.push_back(node->val);
                }
                if(node->left)  q.push(node->left);
                if(node->right)  q.push(node->right);
            }
        }
        return ans;
    }
    */
};