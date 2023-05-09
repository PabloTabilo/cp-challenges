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
    ListNode * merge_sort(ListNode * l1, ListNode * l2){
        ListNode lt;
        ListNode * t = &lt;
        ListNode * h1 = &lt;
        
        while(l1!=NULL && l2 != NULL){
            if(l1->val < l2->val){
                t->next = l1;
                l1 = l1->next;
            }else{
                t->next = l2;
                l2 = l2->next;
            }
            t = t->next;
        }
        if(l1!=NULL){
            t->next = l1;
        }
        if(l2!=NULL){
            t->next = l2;
        }
        return h1->next;
    }

    ListNode * divide_and_conquer(ListNode * head){
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode * l1 = head;
        ListNode * l2 = head;

        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * prev = head;

        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        l1 = divide_and_conquer(head);
        l2 = divide_and_conquer(slow);
        return merge_sort(l1,l2);
    }

    void loop(ListNode * c){
        cout<<"{ ";
        while(c!=NULL){
            cout<<c->val<<" ";
            c=c->next;
        }
        cout<<"}"<<endl;
    }

    ListNode* sortList(ListNode* head) {
        return divide_and_conquer(head);
    }
};
