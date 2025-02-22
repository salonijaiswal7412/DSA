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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> s;
        int i=0,n=traversal.length();
        while(i<n){
            int d=0;
            while(i<n && traversal[i]=='-'){
                i++;d++;
            }
            int val=0;
            while(i<n && isdigit(traversal[i])){
                val=val*10+(traversal[i]-'0');
                i++;
            }
            TreeNode* curr=new TreeNode(val);
            while(s.size()>d){
                s.pop();
            }
            if(!s.empty()){
                if(s.top()->left==nullptr){
                    s.top()->left=curr;
                }
                else s.top()->right=curr;
            }
            s.push(curr);
        }
        while(s.size()>1){
            s.pop();
        }
        return s.top();
        
    }
};
