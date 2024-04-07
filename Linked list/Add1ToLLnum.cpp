int helper(Node *temp){
    if(temp==nullptr)return 1;
    int c=helper(temp->next);
    temp->data+=c;
    if(temp->data<10)return 0;
    temp->data=c-1;
    return 1;
}
Node *addOne(Node *head)
{
    // Write Your Code Here.
    Node *temp=head;
    int c=helper(temp);
    if(c==1){
        Node*n=new Node(1);
        n->next=head;
        head=n;
    }
    return head;

}
