/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        int n=0;
        ListNode* curr=head;
        while(curr!=nullptr){
            n++;
            curr=curr->next;
        }
        k=k%n;
        if(k==0) return head;

        curr=head;
        ListNode* slow=head;
        while(k){
            k--;
            curr=curr->next;
        }
        while(curr->next!=nullptr){
            curr=curr->next;
            slow=slow->next;
        }
        ListNode* newhead=slow->next;
        slow->next=nullptr;
        curr->next=head;
        return newhead;
        
    }
};