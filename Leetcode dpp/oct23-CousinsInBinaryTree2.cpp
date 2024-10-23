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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        int prev=root->val;

        while(!q.empty()){
            int n=q.size();
            int s=0;
            for(int i=0;i<n;i++){
                TreeNode* nn=q.front();
                q.pop();
                int temp=(nn->left ?nn->left->val : 0)+(nn->right?nn->right->val:0);
                if(nn->left){
                    nn->left->val=temp;
                    q.push(nn->left);
                }
                if(nn->right){
                    nn->right->val=temp;
                    q.push(nn->right);
                }
                s+=temp;
                nn->val=prev-nn->val;

            }
            prev=s;
        }
        return root;
        
    }
};