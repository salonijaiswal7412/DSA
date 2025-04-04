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
class FindElements {
public:
    unordered_set<int> s;
    FindElements(TreeNode* root) {
        dfs(root,0);
        
    }
    void dfs(TreeNode* node,int val){
        if(!node) return;
        s.insert(val);
        dfs(node->left,2*val+1);
        dfs(node->right,2*val+2);
    }
    
    bool find(int target) {
        return s.find(target)!=s.end();
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
