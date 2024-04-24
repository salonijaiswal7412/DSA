int height(TreeNode<int>* root, int& d){
    if(!root)return 0;
    int l=height(root->left, d);
    int r=height(root->right,d);
    d=max(d,l+r);
    return 1+max(l,r);
}
int diameterOfBinaryTree(TreeNode<int> *root){
	// Write Your Code Here.
    int d=0;
    height(root,d);
    return d;
}
