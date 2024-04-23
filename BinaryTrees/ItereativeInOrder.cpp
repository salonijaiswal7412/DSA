vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    stack<TreeNode*>s;
    TreeNode* n=root;
    vector<int>ans;
    while(true){
        if(n!=nullptr){
            s.push(n);
            n=n->left;
        }
        else{
            if(s.empty())break;
            n=s.top();
            s.pop();
            ans.push_back(n->data);
            n=n->right;
        }
    }
    return ans;
}
