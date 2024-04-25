bool isLeaf(TreeNode<int>* root){
    return(root->left==nullptr && root->right==nullptr);
}
void addLeft(TreeNode<int>* root, vector<int>& ans){
    TreeNode<int>* c=root->left;
    while(c){
        if(!isLeaf(c))ans.push_back(c->data);
        if(c->left)c=c->left;
        else c=c->right;
    }
}

void addLeaves(TreeNode<int>* root,vector<int>& ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return ;
    }
    if(root->left)addLeaves(root->left, ans);
    if(root->right)addLeaves(root->right, ans);
}

void addRight(TreeNode<int>* root,vector<int>& ans){
    TreeNode<int>* c=root->right;
    vector<int> s;
    while(c){
        if(!isLeaf(c))s.push_back(c->data);
        if(c->right)c=c->right;
        else{
            c=c->left;
        }
    }
    for(int i=s.size()-1;i>=0;i--){
        ans.push_back(s[i]);
    }
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    vector<int> ans;
    if(!root) return ans;
    if(!isLeaf(root))ans.push_back(root->data);
    addLeft(root,ans);
    addLeaves(root,ans);
    addRight(root,ans);
    return ans;
}
