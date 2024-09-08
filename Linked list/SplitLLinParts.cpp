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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int n=0;
        ListNode* curr=head;
        while(curr){
            n++;
            curr=curr->next;
        }
        curr=head;
        int base=n/k;
        int rem=n%k;
        for(int i=0;i<k;i++){
            ListNode* newp=curr;
            int nsize=base+(rem>0?1:0);
            rem--;
            for(int j=0;j<nsize-1 && curr;j++)
            curr=curr->next;

            if(curr){
                ListNode* nextp=curr->next;
                curr->next=nullptr;
                curr=nextp;
            }
            ans.push_back(newp);
        }
        return ans;
        
    }
};