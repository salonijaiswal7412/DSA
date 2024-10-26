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
    map<int,int> l,r,h;
    int height(TreeNode* root){
        if(!root) return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        l[root->val]=lh;
        r[root->val]=rh;
        return 1+max(lh,rh);
    }
    void solve(TreeNode* root,int maxa,int d){
        if(!root) return;
        h[root->val]=maxa;
        solve(root->left,max(maxa,d+r[root->val]),d+1);
        solve(root->right,max(maxa,d+l[root->val]),d+1);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        height(root);
        solve(root->left,r[root->val],1);
        solve(root->right,l[root->val],1);
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(h[queries[i]]);
        }
        return ans;
        
    }
};
