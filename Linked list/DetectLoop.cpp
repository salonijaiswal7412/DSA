
bool detectCycle(Node *head)
{
	//	Write your code here
     Node *slow=head;
    Node *fast=head;
    
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)return true;
    }
    return false;
}
