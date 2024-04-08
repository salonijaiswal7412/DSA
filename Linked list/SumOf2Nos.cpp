Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node *t1=num1;
    Node *t2=num2;
    Node *dummy=new Node(-1);
    Node *curr=dummy;
    int c=0;
    while(t1!=nullptr|| t2!=nullptr){
        int s=c;
        if(t1)s+=t1->data;
        if(t2)s+=t2->data;
        Node *nn=new Node(s%10);
        c=s/10;
        curr->next=nn;
        curr=curr->next;
        if(t1)t1=t1->next;
        if(t2)t2=t2->next;
    }
    if(c){
        Node *nn=new Node(c);
        curr->next=nn;
    }
    return dummy->next;
}
