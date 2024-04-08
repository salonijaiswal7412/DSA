Node * deleteAllOccurrences(Node* head, int k) {
    // Write your code here
    Node *temp=head;
    while(temp!=nullptr){
       if(temp->data==k){
            if(head==temp)head=head->next;
            Node *nextN=temp->next;
            Node *prevN=temp->prev;
            if(nextN)nextN->prev=prevN;
            if(prevN)prevN->next=nextN;
            free(temp);
            temp=nextN;

       
       }
       else{
           temp=temp->next;
       }
   }
   return head;
}
