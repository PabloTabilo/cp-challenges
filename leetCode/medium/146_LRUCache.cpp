// Doubly Linked List
struct DLL {
    int key;
    int val;
    DLL *prev;
    DLL *next;
    DLL() : key(0),val(0), next(nullptr), prev(nullptr) {}
    DLL(int k, int v) : key(k),val(v), next(nullptr), prev(nullptr) {}
    DLL(int k, int v, DLL *next) : key(k),val(v), next(next), prev(nullptr) {}
    DLL(int k, int v, DLL *next, DLL *prev) : key(k),val(v), next(next), prev(prev) {}
};

class LRUCache {
public:
    int capacity; // capacity of the structure
    int items = 0; // items added
    unordered_map<int, DLL *> m; // key -> pointer
    DLL * head = NULL;
    DLL * tail = NULL;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    void loop(){
        DLL * c = head;
        cout<<endl<<"{";
        while(c!=NULL){
            cout<<" {"<<c->key<<","<<c->val<<"} ";
            c=c->next;
        }
        cout<<"}"<<endl;
    }
    
    int get(int key) {
        // The key exist on the data structure
        if(m.find(key)!=m.end()){
            DLL * n = m[key];
            
            // If not parent, this mean that the father is head
            if(n->prev == NULL){
                // structure has more than one item
                if(n->next){
                    head = n->next;
                    head->prev = NULL;
                }
                // structure has only one item
                else{
                    head = n;
                }
            }
            // Node has parent, is not head
            else{
                DLL * p = n->prev;
                
                // Node is not tail
                if(n->next){
                    p->next = n->next;
                    n->next->prev = p;
                }
                // Node is tail
                else{
                    p->next=n;
                }
            }

            // Relocate node to tail
            // if node is not tail
            if(n->next){
                n->next=NULL;
                tail->next = n;
                n->prev=tail;
            }
            tail = n;
            return n->val;
        }
        return -1;
    }

    void put(int key, int value) {
        DLL * n;
        // update
        if(m.find(key)!=m.end()){
            n = m[key];
            n->val=value;
            get(key);

        }
        // add
        else{
            items++;
            n = new DLL(key,value);

            // Exist more than one item
            if(items>1){
                // the number of items added is more than the capacity
                // we need to eliminate node on head and
                // add node on tail
                if(items>capacity){
                    // pointer to delete
                    DLL * del = head;
                    int kd = del->key;

                    // node is only one
                    if(head->next==NULL && capacity==1){
                        head = n;
                    }
                    // update the new least recently used node
                    else{
                        head = head->next;
                        head->prev = NULL;
                    }
                    delete del; // free memory
                    m.erase(kd);
                }
                
                // is not only one node
                // update tail
                if(capacity > 1){
                    n->prev=tail;
                    tail->next = n;
                }
                tail = n;
            }
            // Exist only one item, so assign head and tail to this item
            else{
                head = n;
                tail = n;
            }
        }
        m[key] = n;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
