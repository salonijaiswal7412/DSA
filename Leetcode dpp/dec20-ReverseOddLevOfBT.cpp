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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool isOdd=false;
        while(!q.empty()){
            int n=q.size();
            vector<TreeNode*> temp;
            for(int i=0;i<n;i++){
                auto val=q.front();
                temp.push_back(val);
                if(val->left) q.push(val->left);
                if(val->right) q.push(val->right);
                q.pop();
            }
            if(isOdd){
                int l=0,r=temp.size()-1;
                while(l<=r){
                    swap(temp[l++]->val,temp[r--]->val);
                }
            }
            isOdd=!isOdd;

        }
        return root;
        
    }
};
