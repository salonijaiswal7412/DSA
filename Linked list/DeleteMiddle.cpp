
Node* deleteMiddle(Node* head){
    // Write your code here.
    if(head==nullptr || head->next==nullptr)
    return nullptr;
    Node *slow=head;
    Node *fast=head;
    fast=fast->next->next;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=slow->next->next;
    
    return head;
}
