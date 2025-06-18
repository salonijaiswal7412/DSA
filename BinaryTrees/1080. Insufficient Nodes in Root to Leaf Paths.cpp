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
    TreeNode* dfs(TreeNode* root,int s,int limit){
        if(!root) return nullptr;
        if(!root->left && !root->right){
            if(s+root->val>=limit){
                return root;
            }
            else{
                return nullptr;
            }
        }
        root->left=dfs(root->left,s+root->val,limit);
        root->right=dfs(root->right,s+root->val,limit);
        if(!root->left && !root->right){
            return nullptr;
        }
        return root;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return dfs(root,0,limit);
        
    }
};
