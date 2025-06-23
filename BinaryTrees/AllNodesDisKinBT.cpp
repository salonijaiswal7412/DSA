/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getparent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                parent[curr->left]=curr;
                q.push(curr->left);
                
            }
            if(curr->right){
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*,TreeNode*> parent;
        getparent(root,parent);

        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> vis;
        int level=0;
        q.push(target);
        vis[target]=1;
        while(!q.empty()){
            int n=q.size();
            if(level++==k) break;

            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();

                if(node->left && !vis[node->left]){
                    vis[node->left]=1;
                    q.push(node->left);
                }

                if(node->right && !vis[node->right]){
                    vis[node->right]=1;
                    q.push(node->right);
                }

                if(parent[node] && !vis[parent[node]]){
                    vis[parent[node]]=1;
                    q.push(parent[node]);
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
        
    }
};
