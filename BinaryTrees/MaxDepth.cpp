//using recursion
class Solution {
public:
    int maxDepth(TreeNode* root) {
    if(root==nullptr)return 0;
    int l=maxDepth(root->left);
    int r=maxDepth(root->right);
    return 1+max(l,r);
        
    }
};

//using level order traversal
int heightOfBinaryTree(TreeNode<int> *root)
{
	// Write your code here.
    if(root==nullptr)return 0;
    int c=0;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int s=q.size();
        for(int i=0;i<s;i++){
            TreeNode<int>* n=q.front();
            q.pop();
            if(n->left)q.push(n->left);
            if(n->right)q.push(n->right);
        }
        c++;
    }
    return c;
}
