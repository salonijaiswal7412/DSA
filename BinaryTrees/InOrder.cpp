void inOrderHelper(TreeNode *root, vector<int> &result) {
    if (root == nullptr)
        return;
    
    // Traverse left subtree
    inOrderHelper(root->left, result);
    
    // Visit current node
    result.push_back(root->data);
    
    // Traverse right subtree
    inOrderHelper(root->right, result);
}

vector<int> getInOrderTraversal(TreeNode *root) {
    vector<int> result;
    // Call helper function to perform in-order traversal
    inOrderHelper(root, result);
    return result;
}
