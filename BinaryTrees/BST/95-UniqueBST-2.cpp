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
    vector<TreeNode*> gen(int beg,int end){
        if(beg>end) return {nullptr};

        vector<TreeNode*> ans;
        for(int i=beg;i<=end;i++){
            vector<TreeNode*> left=gen(beg,i-1);
            vector<TreeNode*> right=gen(i+1,end);

            for(auto l:left){
                for(auto r:right){
                    TreeNode* curr=new TreeNode(i);
                    curr->left=l;
                    curr->right=r;
                    ans.push_back(curr);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return vector<TreeNode*>();
        return gen(1,n);
        
    }
};
