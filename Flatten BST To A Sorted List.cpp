TreeNode<int>* flatten(TreeNode<int>* root)
{
    if(!root)   return nullptr;
    if(!root->left && !root->right) return root;

    TreeNode<int>* lhead = flatten(root->left);
    root->left = nullptr;
    root->right = flatten(root->right);
    
    if(lhead) {
        TreeNode<int>* temp=lhead;
        while(temp && temp->right) {
            temp=temp->right;
        }
        temp->right=root;
    } else {
        lhead=root;
    }

    return lhead;

}
