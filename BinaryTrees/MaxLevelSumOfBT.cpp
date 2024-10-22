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
    int maxLevelSum(TreeNode* root) {
        int ans;
        int l = 1, maxv = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> level;
            int s = 0;
            for (int i = 0; i < n; i++) {

                TreeNode* nn = q.front();
                q.pop();
                if (nn->left != NULL)
                    q.push(nn->left);
                if (nn->right != NULL)
                    q.push(nn->right);
                s += nn->val;
            }

            if (s > maxv) {
                maxv = s;
                ans = l;
            }
            if (s == maxv) {
                ans = min(ans, l);
            }
            l++;
        }
        return ans;
    }
};
