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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long>p;
        if(root==NULL) return -1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> level;
            for(int i=0;i<n;i++){
                TreeNode* nn=q.front();
                q.pop();
                if(nn->left!=NULL) q.push(nn->left);
                if(nn->right!=NULL) q.push(nn->right);
                level.push_back(nn->val);
            }
            long long s=0;
            for(auto i:level){
                s+=i;
            }
            p.push(s);
        }
        long long ans=0;
        while(!p.empty() && k){
            k--;
            ans=p.top();
            p.pop();
            

        }
        return (k==0)?ans:-1;
        
    }
};
