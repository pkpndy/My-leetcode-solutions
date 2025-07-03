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
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, 
        vector<int>& inorder, int inStart, int inEnd, map<int, int>& inmap)
        {
            //these start and end pointers in preorder and inorder vectors
            //which will basically mark the range of the elements to create tree
            if(preStart > preEnd || inStart > inEnd)    return nullptr;

            //since preorder is {root, left, right}, 
            //so in any preorder array the first element will always be root
            TreeNode* root = new TreeNode(preorder[preStart]);
            //get the index of the root element in the inorder vector, 
            //so that we can divide the left subtree and right subtree as inorder is {left, root, right}
            int inRoot = inmap[root->val];
            //calculate the range of elements that make up for the left subtree
            int numsLeft = inRoot - inStart;

            //PREORDER vector the left subtree starts after the first root element and
            //has the same nodes as the left subtree of the inorder hence add the numsleft
            root->left = buildTree(preorder, preStart+1, preStart+numsLeft,
                                    inorder, inStart, inRoot-1, inmap);
            //INORDER starts from the begining and ends just before root since its {left, root, right}


            //PREORDER will have prestart+numsleft+1 because prestart will help to reach the current
            //tree preorder then numsleft for skipping the left subtree elements and 
            //then +1 for the index just after 
            root->right = buildTree(preorder, preStart+numsLeft+1, preEnd,
                                    inorder, inRoot+1, inEnd, inmap);
            //INORDER is simple the elements just after the root till the end

            return root; //return the new tree root
        }            
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //we will map number to its index in the inorder vector, to access it in O(1) time
        map<int, int> inmap;
        for(int i=0; i<inorder.size(); i++) {
            inmap[inorder[i]] = i;
        }

        //send the vectors, start and end to be used in each recursive call and the map
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inmap);

    }
};