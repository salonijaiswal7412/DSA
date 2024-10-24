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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> level;
            while(n>0){
                TreeNode* nn=q.front();
                q.pop();
                if(nn->left) q.push(nn->left);
                if(nn->right) q.push(nn->right);
                level.push_back(nn->val);
                n--;
            }
            ans.push_back(level);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};