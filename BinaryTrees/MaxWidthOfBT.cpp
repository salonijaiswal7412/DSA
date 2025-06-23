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
    int widthOfBinaryTree(TreeNode* root) {
        const int mod=1e9+7;
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        long long int ans=0;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            int mini=q.front().second;
            long long int f,l;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front().first;
                long long int id=q.front().second-mini;
                q.pop();

                if(i==0) f=id;
                if(i==n-1) l=id;

                if(node->left) q.push({node->left,id*2+1});
                if(node->right) q.push({node->right,2*id+2});
            }
            ans=max(ans,l-f+1);
        }
        return ans;
        
    }
};
