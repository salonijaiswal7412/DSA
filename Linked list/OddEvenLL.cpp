class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* odd=head;
        ListNode *even=head->next;
        ListNode* evenh=head->next;
        while(even!=NULL && even->next!=NULL){
            odd->next=even->next;
            even->next=odd->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=evenh;
        return head;
        
    }
};
