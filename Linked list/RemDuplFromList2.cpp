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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> m;
        ListNode* t=head;
        while(t){
            m[t->val]++;
            t=t->next;
        }
        ListNode *ans=nullptr,*tail=nullptr;
        for(auto i:m){
            if(i.second==1){
                ListNode* t=new ListNode(i.first);
                if(!ans){
                    ans=t;
                    tail=t;
                }
                else{
                    tail->next=t;
                    tail=tail->next;
                }
            }
        }
        return ans;
        
    }
};