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
    ListNode* merge(ListNode* l1,ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val>l2->val){
            swap(l1,l2);
        }
        ListNode* head=l1;
        while(l1 && l2){
            ListNode* temp=nullptr;
            while(l1 && l1->val<=l2->val){
                temp=l1;
                l1=l1->next;
            }
            temp->next=l2;
            swap(l1,l2);
        }
        return head;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;

        while(lists.size()>1){
            int n=lists.size();
            ListNode* l1=lists[n-1];
            ListNode* l2=lists[n-2];
            lists.pop_back();
            lists.pop_back();
            l1=merge(l1,l2);
            lists.push_back(l1);

            
            
        }
        return lists[0];

        
    }
};
