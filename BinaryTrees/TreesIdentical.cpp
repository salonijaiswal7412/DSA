bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here. 	 
    if(root1==nullptr||root2==nullptr){
        return(root1==root2);
    }
    return(root1->data==root1->data)&&(identicalTrees(root1->left, root2->left))&&(identicalTrees(root1->right, root2->right));
}
