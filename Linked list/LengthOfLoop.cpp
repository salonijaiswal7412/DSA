int len(Node *slow,Node *fast){
    int c=1;
    fast=fast->next;
    while(fast!=slow){
        c++;
        fast=fast->next;
    }
    return c;
}
int lengthOfLoop(Node *head) {
    // Write your code here
    Node *fast=head;
    Node *slow=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)return len(slow,fast);
    }
    return 0;
}
