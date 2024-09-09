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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int l = 0, r = n - 1, t = 0, b = m - 1;
        ListNode* curr = head;
        while (l <= r && t <= b) {
            for (int i = l; i <= r; i++) {
                if (curr != nullptr) {
                    ans[t][i] = curr->val;
                    curr = curr->next;
                } 
            }
            t++;
            for (int i = t; i <= b; i++) {
                if (curr != nullptr) {
                    ans[i][r] = curr->val;
                    curr = curr->next;
                }
            }
            r--;
            if (t <= b) {
                for (int i = r; i >= l; i--) {
                    if (curr != nullptr) {
                        ans[b][i] = curr->val;
                        curr = curr->next;
                    } 
                }
                b--;
            }
            if(l<=r){
                for(int i=b;i>=t;i--){
                     if(curr!=nullptr){
                    ans[i][l]=curr->val;
                    curr=curr->next;
                }
                
                }
                l++;
            }
            
        }
        return ans;
    }
};