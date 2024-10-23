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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            bool a=false,b=false;
            for(int i=0;i<n;i++){
                TreeNode *nn=q.front();
                q.pop();
                if(nn->val==x)a=true;
                if(nn->val==y) b=true;
                if(nn->left && nn->right)
                {
                    if((nn->left->val==x && nn->right->val==y)||(nn->left->val==y && nn->right->val==x))
                    return false;
                }
                if(nn->left) q.push(nn->left);
                if(nn->right) q.push(nn->right);
            }
            if(a && b) return true;
        }
        return false;
        
    }
};