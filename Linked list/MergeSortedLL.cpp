class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode dummy;
        ListNode* nn = &dummy; 

       
        while (l1 && l2) {
            if (l1->val < l2->val) {
                nn->next = l1;
                l1 = l1->next;
            } else {
                nn->next = l2;
                l2 = l2->next;
            }
            nn = nn->next;  
        }

        
        if (l1) {
            nn->next = l1;
        } else {
            nn->next = l2;
        }

        return dummy.next;
    }
};
