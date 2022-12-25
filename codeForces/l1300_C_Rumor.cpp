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

struct node{
    int vertex;
    ll cost;
};

bool operator<(const node& n1, const node& n2){
    return n1.vertex < n2.vertex;
}

class Graph{
    int numVertices;
    map<int,node> m;
    map<node,bool> visited;
    map<node, vector<node>> adj;
    public:
        Graph(int V);
        void addNode(node n);
        void addEdge(int src_vertex, int dest_vertex);
        void viewGraph();
        ll mydfs(node n);
        ll DFS();
};

Graph::Graph(int V){
    this->numVertices=V;
}

void Graph::addNode(node n){
   adj[n].push_back({}); 
   visited[n]=false;
   m[n.vertex]=n;
}

void Graph::addEdge(int src_vertex, int dest_vertex){
    node src = m[src_vertex];
    node dest = m[dest_vertex];
    adj[src].push_back(dest); 
    adj[dest].push_back(src); 
}

void Graph::viewGraph(){
    for(auto i : adj){
        cout<<"i.first.vertex: "<<i.first.vertex<<"; i.first.cost: "<<i.first.cost<<endl;
        for(auto n : adj[i.first]){
            cout<<"n.vertex: "<<n.vertex<<"; n.cost: "<<n.cost<<endl;
        }
        cout<<"---------------------------------"<<endl;
    }
}

ll Graph::mydfs(node cu){
    visited[cu]=true;
    ll c=cu.cost;
    ll best_cost=1e9+1;
    for(auto n : adj[cu]){
        if(n.vertex==0) continue;
        if(!visited[n]){
            best_cost=min(best_cost,mydfs(n));
        }
    }
    return min(c,best_cost);
}

ll Graph::DFS(){
    ll res=0;
    for(auto i : adj){
        //cout<<"from this node.vertex,node.cost="<<i.first.vertex<<","<<i.first.cost<<endl;
        if(!visited[i.first]){
            res+=mydfs(i.first);
        }
        //cout<<"res until now!: "<<res<<endl;
    }
    return res;
}

void solve(){
    int n,m;
    cin>>n>>m;
    Graph g(n);
    node t;
    for(int i=0;i<n;i++){
        t.vertex=i+1;
        cin>>t.cost;
        g.addNode(t);
    }
    int v1,v2;
    for(int c=0;c<m;c++){
        cin>>v1>>v2;
        g.addEdge(v1,v2);
    }
    //g.viewGraph();
    cout<<g.DFS()<<endl;
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

