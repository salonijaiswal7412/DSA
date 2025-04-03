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
    ListNode* partition(ListNode* head, int x) {
        ListNode a(0),b(0);
        ListNode*prev=&a;
        ListNode* later=&b;
        while(head){
            if(head->val<x){
                
                prev->next=head;
                prev=prev->next;
            }
            else{
                
                later->next=head;
                later=later->next;
            }
            head=head->next;
        }
        later->next=nullptr;
        prev->next=b.next;
        return a.next;
        
    }
};
