void post(TreeNode*root,vector<int>& ans){
    if(root==nullptr)return;
    post(root->left,ans);
    post(root->right,ans);
    ans.push_back(root->data);
}
vector<int> postorderTraversal(TreeNode *root)
{
    // Write your code here
    vector<int>ans;
    post(root,ans);
    return ans;

}
