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
    int gcd(int a,int b){
        while(b!=0){
            int t=b;
            b=a%b;
            a=t;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==nullptr|| head->next==nullptr) return head;

        ListNode* n1=head;
        ListNode* n2=head->next;

        while(n2!=nullptr){
            int g=gcd(n1->val,n2->val);
            ListNode* nn=new ListNode(g);

            n1->next=nn;
            nn->next=n2;

            n1=n2;
            n2=n2->next;
            
        }
        return head;
        
    }
};