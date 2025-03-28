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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(!root)return ans;
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
           
            double s=0;
            for(int i=0;i<n;i++){
                TreeNode* n=q.front();
                q.pop();
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
                s+=n->val;

            }
            ans.push_back(static_cast<double>(s)/n);

        }
        
        return ans;
    }
};