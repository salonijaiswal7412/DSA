//using 2 stacks
vector<int> postorderTraversal(TreeNode *root)
{
    // Write your code here
    vector<int>ans;
    if(root==NULL)return ans;
    stack<TreeNode*> s1,s2;
    s1.push(root);
    while(!s1.empty()){
        root=s1.top();
        s1.pop();
        s2.push(root);
        if(root->left)
        s1.push(root->left);
        if(root->right)
        s1.push(root->right);
    }
    while(!s2.empty()){
        ans.push_back(s2.top()->data);
        s2.pop();
    }
    return ans;
}
