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

class Graph{
    private:
        vector<int> visited;
        map<int,vector<int>> adj;
    public: 
        map<int,int> id_gr;
        map<int,set<int>> gr_set;
        Graph(int n);
        void add_edge(int n1, int n2);
        void search();
        void dfs(int cn, int group);
};

Graph::Graph(int n){
    for(int i=1;i<=n;i++){
        adj[i].push_back(i);
        visited.push_back(false);
    }
}

void Graph::add_edge(int n1, int n2){
    adj[n1].push_back(n2);
    adj[n2].push_back(n1);
}

void Graph::dfs(int cn, int group){
    id_gr[cn]=group;
    gr_set[group].insert(cn);
    visited[cn-1]=true;
    for(auto nb : adj[cn]){
        if(!visited[nb-1]){
            dfs(nb,group);
        }
    }
}

void Graph::search(){
    int group=0;
    for(auto n : adj){
        if(!visited[n.first-1]){
            group++;
            dfs(n.first, group);
        }
    }
}

void solve(){
    int n, m;
    cin>>n>>m;
    Graph g(n);
    int sz;
    for(int i=0;i<m;i++){
        cin>>sz; 
        vector<int> gr(sz);
        for(int e=0;e<sz;e++){
            cin>>gr[e];
        }
        if(sz > 1){
            for(int e=1;e<sz;e++){
                g.add_edge(gr[e-1],gr[e]);
            }
            if(sz>=3){
                g.add_edge(gr[0],gr[sz-1]);
            }
        }
    }
    g.search();
    for(auto i : g.id_gr){
        cout<<g.gr_set[i.second].size()<<" ";
    }
    cout<<endl;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    auto start1 = high_resolution_clock::now();
    // read & write file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
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

