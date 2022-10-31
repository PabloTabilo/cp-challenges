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
    void p_v(vector<int> p, int n){
        for(int i=0;i<n;i++){
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }
    void p_l(ListNode* l){
        while(l != nullptr){
            cout<<l->val<<" ";
            l=l->next;
        }
        cout<<endl;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int pos = 0;
        int n = 0;
        ListNode * p = head;
        vector<int> play(500,-501);
        while(p != nullptr){
            play[pos] = p->val;
            p = p->next;
            pos++;
            n++;
        }
        vector<int> c(n,-501);
        //copy
        for(int i=0;i<n;i++) c[i] = play[i];
        int i=left-1;
        int j=right-1;
        /reorder
        while(j>=left-1) c[i++] = play[j--];
        ListNode * h = new ListNode(c[0],nullptr);
        ListNode * l = h;    
        for(int i=1;i<n;i++){    
            ListNode * t = new ListNode(c[i],nullptr);
            l->next=t;
            l=l->next;
        }
        return h;
    }
};

