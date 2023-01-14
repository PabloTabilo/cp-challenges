#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<iterator>
#include<stack>
#include<set>
#include<unordered_map>
#include<map>
#include<math.h>
#include<limits>
#include<iomanip>
#include<sstream>
#include<tuple>
#include<chrono>
#include<cstring>

using namespace std;
using namespace chrono;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define _USE_MATH_DEFINES
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second

typedef long int int32;
typedef unsigned long int uint32;
typedef long long ll;
typedef unsigned long long int ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

struct Node{
    int id=0;
    int a=0;
    int c=0;
    struct Node * parent = nullptr;
    vector<Node *> children;
    Node(){}
};

class RootedTree{
    private:
        Node * root = nullptr;
        map<int, Node*> mymap; // fast search 
    public:
        RootedTree(int a, int c);
        void add_vertex(int id, int pi, int a, int c);
        pair<int,ll> get_min(int vi, int wi);
        void dfs(Node * n);
        void print_tree();
};

RootedTree::RootedTree(int a, int c){
    Node * r = new Node();
    r->id=0;
    r->a=a;
    r->c=c;
    root = r;
    mymap[0]=root;
}

void RootedTree::add_vertex(int id,int pi, int a, int c){
    Node * new_child = new Node();
    new_child->a=a;
    new_child->c=c;
    new_child->id=id;
    // search where is parent node with id=pi
    Node * pparent = mymap[pi];
    new_child->parent = pparent;
    // and add current child to parent childs pointers
    pparent->children.push_back(new_child); 
    mymap[id]=new_child;
}

pair<int,ll> RootedTree::get_min(int vi, int wi){
    pair<int,ll> res={0,0};
    Node * n = mymap[vi];
    vector<int> v; // save all ids from n to root;
    while(n != mymap[0]){
        v.push_back(n->id);
        n = n->parent;
    }
    v.push_back(0);
    int ns=v.size();
    Node * curr;
    int ag=0; 
    ll am=0;
    for(int i=ns-1;i>=0;i--){
        curr = mymap[v[i]];
        int ca = curr->a;
        int cc = curr->c;
        if(ca > 0 && wi > 0){
           if(wi>ca){
                curr->a=0;
                wi-=ca;
                am+=((ll)ca*(ll)cc);
                ag+=ca;
           }else if(wi<=ca){
                curr->a-=wi;
                am+=((ll)wi*(ll)cc);
                ag+=wi;
                break;
           }
        }
    }
    res.first=ag;
    res.second=am;
    return res;
}

void RootedTree::dfs(Node * curr){
    if(curr != nullptr){
        int id = curr->id;
        int a = curr->a;
        int c = curr->c;
        cout<<"id,a,c="<<id<<","<<a<<","<<c<<endl;
        vector<Node *> childs = curr->children;
        int n=childs.size();
        cout<<"childs.size()="<<n<<endl;
        for(auto x : childs){
            cout<<"My parent is: "<<id<<endl;
            dfs(x);
        }
    }
}

void RootedTree::print_tree(){
    dfs(root);
}

bool debug_me=false;

void solve(){
    int q, a, c;
    cin>>q>>a>>c;
    int ask, pi, vi, wi;
    RootedTree t(a,c);
    if(debug_me) t.print_tree();
    int id=1;
    while(q--){
        cin>>ask;
        if(ask==1){
            cin>>pi>>a>>c;
            t.add_vertex(id,pi,a,c);
        }else{
            cin>>vi>>wi;
            pair<int,ll> res = t.get_min(vi,wi);// pair first=amount of gold; second=min amount of money spend
            cout<<res.first<<" "<<res.second<<endl;
        }
        id++;
        if(debug_me) t.print_tree();
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    auto start1 = high_resolution_clock::now();
    // read & write file
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << endl;
#endif
    return 0;
}

