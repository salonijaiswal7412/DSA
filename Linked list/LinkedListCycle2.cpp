//using hashmap
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * temp=head;
        unordered_map<ListNode*,int> m;
        while(temp){
            if(m.find(temp)!=m.end()){
                return temp;
            }
            m[temp]++;
            temp=temp->next;
        }
        return nullptr;
        
    }
};
//using slow and fast pt;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next){
            return nullptr;
        }
        ListNode* fast=head,*slow=head,*beg=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                while(beg!=slow){
                    beg=beg->next;
                    slow=slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
