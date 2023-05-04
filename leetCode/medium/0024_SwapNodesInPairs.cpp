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
    ListNode* swapPairs(ListNode* head) {
        ListNode * c = head;
        int cn, nn;
        while(c != nullptr && c->next != nullptr){
            cn = c->val;
            nn = c->next->val;
            c->val=nn;
            c->next->val=cn;
            //cout<<"c="<<cn<<"; nn="<<nn<<endl;
            c=c->next->next;
        }
        return head;
    }
};
