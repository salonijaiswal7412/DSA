//approach 1 counting no of elements in ll
Node* removeKthNode(Node* head, int k)
{
    // Write your code here.
    int c=0;
    Node *temp=head;
    while(temp!=nullptr){
        c++;
        temp=temp->next;
    }
    if(c==k){return head->next;}
    int s=c-k;
    temp=head;
    while(temp!=nullptr){
        s--;
        if(s==0)
        break;
        temp=temp->next;
    }
    Node *del=temp->next;
    temp->next=temp->next->next;
    free(del);
    return head;
}
//approach 2 using slow and fast
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow=head;
        ListNode *fast=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast==nullptr)return head->next;
        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode *del=slow->next;
        slow->next=slow->next->next;
        delete(del);
        return head;
        
    }
};
