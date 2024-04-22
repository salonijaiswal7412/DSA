vector<int> preOrder(TreeNode<int> * root){
    // Write your code here.
    vector<int>result;
    if(root==nullptr)
    return result;
         vector<TreeNode<int> *> stack;
    stack.push_back(root);

    while (!stack.empty()) {
        TreeNode<int> *node = stack.back();
        stack.pop_back();
        result.push_back(node->data);

        // Push right child first, so it gets processed after left child
        if (node->right != NULL) {
            stack.push_back(node->right);
        }
        if (node->left != NULL) {
stack.push_back(node->left);
        }
    }

    return result;



}
