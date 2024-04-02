
Node * deleteLastNode(Node *head) {
    // Write your code here
    Node *temp=head;
    if(temp->next==nullptr){
        return nullptr;
    }
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
   
    free (temp->next);
    temp->next=nullptr;
    return head;
}
