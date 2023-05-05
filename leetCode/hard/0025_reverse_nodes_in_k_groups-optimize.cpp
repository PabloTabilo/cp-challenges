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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k>1 && head->next){
            // Space -> O(1)
            int n = 0; // number of nodes in the LL
            // get number of nodes on LL
            // O(n)
            ListNode * l = head;
            while(l!=NULL){
                n++;
                l = l->next;
            }

            int i = 0; // number of nodes in k group
            int p = 0; // number p of nodes in LL visited
            int nk = n/k; // number of groups
            int nki = 0; // number of groups at moment i
            
            ListNode * start = NULL; // start reverse
            ListNode * end = NULL; // end reverse
            ListNode * last_k = NULL; // last k group the we need to unite with current k factible group

            ListNode * nxt = head->next; // to maintain the order of the LL
            ListNode * change = head; // node to change next pointer
            ListNode * prev = head; // prev pointer that we need to assign to change->next pointer

            // O(n) : n >> number of nodes
            while(change!=NULL){
                i++;
                n++;
                p++;

                // reverse
                // this is first node to reverse start *
                if(i==1){
                    start = change;
                    change->next=NULL;
                }
                // this is any other node diff to start *
                else{
                    change->next = prev;
                }
                // the last node was the last one of the group
                if(i == k){
                    // if end is null change head, is the first k team
                    if(end == NULL){
                        head = change;
                    }
                    // the last node analyze
                    end = change;
                    // if exist a group, vinculate with the last node, because is first
                    if(last_k){
                        last_k->next=end;
                    }
                    // last_k nodes always be the first analyze
                    last_k = start;
                    // reboot i >> number of nodes of k group is 0
                    i = 0;
                    // nki + 1, because at this moment we have a factible group
                    nki++;
                }
                // complete number of groups
                if(nki == nk){
                    // the LL is not finished
                    if(p<n){
                        // must be exist a last_k group for vinculate with the next LL nodes
                        if(last_k){
                            last_k->next = nxt;
                        }
                    }
                    break;
                }
                
                prev = change;
                change = nxt;
                nxt = nxt->next;
            }
        }
        // SC : O(1)
        // TC : O(n + n) -> O(n)
        return head;
    }
};
