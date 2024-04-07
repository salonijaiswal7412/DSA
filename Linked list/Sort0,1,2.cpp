Node* sortList(Node *head){
    // Write your code here.
    if(head==nullptr||head->next==nullptr)return head;
    Node *zeroH=new Node(-1);
    Node *oneH=new Node(-1);
    Node *twoH=new Node(-1);

    Node *zero=zeroH;
    Node *one=oneH;
    Node *two=twoH;

    Node *temp=head;
    while(temp){
        if(temp->data==0){
            zero->next=temp;
            zero=zero->next;
        }
        else if(temp->data==1){
            one->next=temp;
            one=one->next;
        }
        else{
            two->next=temp;
            two=two->next;
        }
        temp=temp->next;
    }
    zero->next=(oneH->next)?(oneH->next):(twoH->next);
    one->next=twoH->next;
    two->next=nullptr;
    Node *n=zeroH->next;
    delete oneH;
    delete zeroH;
    delete twoH;
    return n;
}
