Node * insertAtTail(Node *head, int k) {

    // Write your code here

    Node* curr = new Node(k);

 

    if(head == NULL)

    {

        return curr;

    }

    Node* temp = head;

    while(temp->next!=NULL)

    {

        temp = temp-> next;

    }

    Node* temp1=temp;

    temp-> next= curr;

    curr->prev=temp1;

    curr->next=NULL;

 

    return head;

}
