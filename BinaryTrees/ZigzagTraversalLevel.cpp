//leetcode-103
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool flag = true; // true for L->R false for R->L
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            for (int i = 0; i < size; i++) {
                TreeNode* n = q.front();
                q.pop();
                int ind = (flag) ? i: (size - 1 - i); // if true direct entry otherwise reverse entry
                level[ind] = n->val;
                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }
            flag = !flag;
            ans.push_back(level);
        }
        return ans;
    }
};
