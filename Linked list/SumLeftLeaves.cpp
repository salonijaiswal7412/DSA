class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int s=0;
        if(root->left &&!root->left->left && !root->left->right)
        s+=root->left->val;
        s+=sumOfLeftLeaves(root->left);
        s+=sumOfLeftLeaves(root->right);

        return s;

        
    }
};
