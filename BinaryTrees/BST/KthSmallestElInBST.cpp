/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void in(TreeNode* root,int& c,int& ans,int k){
        if(root==NULL) return;
        in(root->left,c,ans,k);
        c++;
        if(c==k){
            ans=root->val;
            return;
        }
        in(root->right,c,ans,k);

    }
    int kthSmallest(TreeNode* root, int k) {
        int c=0,ans;
        in(root,c,ans,k);
        return ans;
        
    }
};