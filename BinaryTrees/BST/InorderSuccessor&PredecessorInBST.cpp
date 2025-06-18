pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    pair<int,int> ans={-1,-1};
    TreeNode* pre=NULL;
    TreeNode* succ=NULL;
    TreeNode* temp=root;
    while(temp){
        if(key>=temp->data){
            temp=temp->right;
        }
        else{
            succ=temp;
            temp=temp->left;
        }
    }
    temp=root;
    while(temp){
        if(key<=temp->data){
            temp=temp->left;
        }
        else{
            pre=temp;
            temp=temp->right;
        }
    }
    if(pre)ans.first=pre->data;
    if(succ)ans.second=succ->data;
    return ans;
}
