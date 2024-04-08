vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.
    vector<pair<int,int>> ans;
    if(head==nullptr)return ans;
    Node *left=head;
    Node *right=head;
    while(right->next!=nullptr){
        right=right->next;
    }
    while(left->data<right->data){
        int s=left->data+right->data;
        if(s==k){
            ans.push_back({left->data,right->data});
            left=left->next;
            right=right->prev;
        }
        else if(s<k){
            left=left->next;
        }
        else{
            right=right->prev;
        }
    }
    return ans;
}
