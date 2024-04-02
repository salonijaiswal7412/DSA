
Node *deleteLast(Node *list){
    // Write your code here
    Node *temp=list;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;

    return list;
    
}
