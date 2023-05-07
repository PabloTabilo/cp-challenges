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
    void loop(ListNode * h){
        ListNode * l = h;
        cout<<"{ ";
        while(l!=nullptr){
            cout<<l->val<<" ";
            l = l->next;
        }
        cout<<"}"<<endl;    
    }
    ListNode* insertionSortList(ListNode* head) {
        if(head->next){
            ListNode * l = head->next->next; // follow original order
            ListNode * c = head->next; // apply change to c
            // first element always is sorted
            head->next = NULL;
            while(c!=nullptr){
                ListNode * comp = head; // compare val vs c val
                ListNode * prev = NULL;
                c->next = NULL;
                // check the position for c
                while(comp!=c && comp!=NULL && c->val > comp->val){
                    prev = comp;
                    comp = comp->next;
                }
                // if c is between two valid pointers
                if(c!=comp && prev!=NULL){
                    prev->next = c;
                    c->next = comp;
                }
                // c must be on head
                else if(prev==NULL){
                    c->next = comp;
                    head = c;
                }
                c = l;
                if(l) l = l->next;
            }
        }
        return head;
    }
};
