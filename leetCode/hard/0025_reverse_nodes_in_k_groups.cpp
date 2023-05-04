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
    void reverse(ListNode * start, ListNode * end){
        ListNode * nxt = start->next; // to maintain the order of the LL
        ListNode * change = start; // node to change next pointer
        ListNode * prev = start; // prev pointer that we need to assign to change->next pointer
        
        while(true){
            /*
            cout<<"----------------"<<endl;
            cout<<"nxt->val = "<<nxt->val<<endl;
            cout<<"change->val = "<<change->val<<endl;
            cout<<"prev->val = "<<prev->val<<endl;
            */
            if(change == start){
                change->next=NULL;
            }else{
                change->next = prev;
            }
            
            if(change == end){
                break;
            }
            prev = change;
            change = nxt;
            nxt = nxt->next;
        }
        //cout<<"----------------"<<endl;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k>1 && head->next){
            // Space -> O(1)
            int n = 0; // number of node in the LL
            int i = 0; // number of node in k group
            ListNode * l = head;
            ListNode * start = NULL; // start reverse
            ListNode * end = NULL; // end reverse
            ListNode * last_k = NULL; // last k group the we need to unite with current k factible group

            ListNode * p = NULL;
            // O(n) : n >> number of nodes
            while(l!=NULL){
                i++;
                n++;
                /*
                cout<<"i = "<<i<<endl;
                cout<<"n = "<<n<<endl;
                cout<<"k = "<<k<<endl;
                */
                if(i==1){
                    start = l;
                }
                //cout<<"start->val = "<<start->val<<endl;
                if(n%k==0){
                    end = l;
                    //cout<<"end->val = "<<end->val<<endl;
                    p = l;
                    l = l->next;
                    // O(k) : k >> number of nodes to reverse
                    reverse(start, end);
                    if(last_k != NULL){
                        last_k->next = end;
                    }else{
                        head = end;
                    }
                    last_k = start;
                    i=0;
                }else{
                    p = l;
                    l=l->next;
                }
            }
            if(i>0){
                last_k->next = start;
            }
        }
        // SC : O(1)
        // TC : O(n*k)

        // optimize -> O(n*k) to O(n)
        return head;
    }
};
