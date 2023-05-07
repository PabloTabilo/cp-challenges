/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        Node * start = NULL;
        unordered_map<Node*,Node*> v; // is visited
        stack<Node*> s; // current
        stack<Node*> c; // copy of current
        if(node){
            start = new Node(node->val);
            s.push(node);
            c.push(start);

            while(!s.empty()){
                Node * trav = s.top(); // travel on original graph
                Node * n_trav = c.top(); // travel on new copy graph
                s.pop();
                c.pop();

                v[trav] = n_trav; // trav * = new trav *
                
                for(auto n : trav->neighbors){

                    if(v.find(n)==v.end()){

                        Node * nn = new Node(n->val);
                        s.push(n);
                        c.push(nn);
                        v[n] = nn;
                        n_trav->neighbors.push_back(nn);
                    }else{

                        n_trav->neighbors.push_back(v[n]);
                    }
                }
            }
        }
        return start;
    }
};
