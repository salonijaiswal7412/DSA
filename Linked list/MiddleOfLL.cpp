//brute force approach time complexity O(N+N/2)

Node *findMiddle(Node *head) {
    // Write your code here
    int c=0;
    Node *temp=head;
    while(temp!=nullptr){
        c++;
        temp=temp->next;
    }
    int mid=(c/2)+1;
    temp=head;
    while(temp!=nullptr){
        mid--;
        if(mid==0)break;
        temp=temp->next;
    }
    return temp;
}

//tortoise hare approach timecomplexity O(N/2)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};
