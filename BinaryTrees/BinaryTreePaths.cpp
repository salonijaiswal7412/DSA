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
    bool isleaf(TreeNode* root){
        return (!root->left && !root->right);
    }

    void gen(TreeNode* node,vector<string>& ans,string& s){
        if(!node) return;
        int n=s.size();
        if(!s.empty()) s+="->";
        s+=to_string(node->val);
        if(isleaf(node)){
            ans.push_back(s);
            
        }
        else{
        gen(node->left,ans,s);
        gen(node->right,ans,s);
        }
        s.resize(n);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
    vector<string> ans;
    if(!root) return ans;
    string s="";
    gen(root,ans,s);
    return ans;
    }
};
