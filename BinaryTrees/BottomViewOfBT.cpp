/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
vector<int> bottomView(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(!root) return ans;
    map<int,int> m;
    queue<pair<TreeNode<int>*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto f=q.front();
        q.pop();
        TreeNode<int>* node=f.first;
        int x=f.second;

        m[x]=node->data;

        if(node->left) q.push({node->left,x-1});
        if(node->right) q.push({node->right,x+1});

    }
    for(auto i:m){
        ans.push_back(i.second);
    }
    return ans;

}
