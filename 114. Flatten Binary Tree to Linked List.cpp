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
    TreeNode* flat(TreeNode* node) {
        // Base case 1: Empty node
        if (node == nullptr) return nullptr;
        
        // Base case 2: Leaf node (It is its own tail)
        if (node->left == nullptr && node->right == nullptr) return node;

        // Step 1: Flatten both halves and get their tails
        TreeNode* leftTail = flat(node->left);
        TreeNode* rightTail = flat(node->right);

        // Step 2: If left subtree exists, perform the stitching
        if (leftTail != nullptr) {
            // Store the original right child
            TreeNode* originalRight = node->right;
            
            // Move left flattened sequence to the right side
            node->right = node->left;
            node->left = nullptr; // Crucial step! Clear the left pointer, only for the node we have
            
            // Connect the tail of the left sequence to the head of the right sequence
            leftTail->right = originalRight;
        }
        
        // Step 3: Return the ultimate tail of the current modified tree
        if (rightTail != nullptr) return rightTail; //if there was any right then send tail of that
        return leftTail; //if there was no right then leftTail became the right skewed tree tail
    }

    void flatten(TreeNode* root) {
        flat(root);
    }
};
