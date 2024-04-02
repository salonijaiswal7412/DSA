Node* reverseDLL(Node* head)
{   
    // Write your code here   
    if(head==nullptr||head->next==nullptr)
    return head;
    Node *temp=head;
    Node *back=nullptr;
    while(temp!=nullptr){
        back=temp->prev;
        temp->prev=temp->next;
        temp->next=back;
        temp=temp->prev;
    }
    return back->prev;
}
