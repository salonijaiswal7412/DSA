//using extra stack
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        stack<int> s;
        while(temp!=nullptr){
            s.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp!=nullptr){
            temp->val=s.top();
            s.pop();
            temp=temp->next;
        }
        return head;
        
    }
};

//Iterative Approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *temp=head;
        ListNode *prev=nullptr;
        while(temp!=nullptr){
            ListNode *front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;

        }
        return prev;
        
    }
};

//recursive approach
Node* reverseLinkedList(Node *head)
{
    if (head==nullptr||head->next==nullptr)
    return head;
    Node * newHead=reverseLinkedList(head->next);
    Node *front=head->next;
    front->next=head;
    head->next=nullptr;
    return newHead;
   
}
