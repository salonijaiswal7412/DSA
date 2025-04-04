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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        return solve(nums,l,h);
        
    }
    TreeNode* solve(vector<int>& nums,int l,int h){
        if(l>h) return nullptr;
        int mid=(l+h)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=solve(nums,l,mid-1);
        root->right=solve(nums,mid+1,h);
        return root;
    }
};
