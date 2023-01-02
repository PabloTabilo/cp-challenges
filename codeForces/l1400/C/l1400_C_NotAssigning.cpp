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

// A hash function used to hash a pair of any kind
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};

class Tree{
private:
    map<int,vector<int>> a;
    unordered_map<pair<int,int>,int,hash_pair> e;
    vector<bool> v;
    int n;
public:
    Tree(int n);
    void add_edge(int u, int v);
    bool is_poss();
    void assign_me();
    void check_edges(vector<pair<int,int>> vp);
    bool all_visited();
};

Tree::Tree(int n){
    this->n=n;
    for(int i=0;i<n;i++) v.push_back(false);
}

void Tree::add_edge(int u, int v){
    a[u].push_back(v);
    a[v].push_back(u);
    int p1 = min(u,v);
    int p2 = max(u,v);
    pair<int,int> p = {p1,p2};
    e[p]=2;
}

bool Tree::is_poss(){
    int degree=0;
    for(auto x : a){
        degree=x.second.size();
        if(degree>=3) return false;
    }
    return true;
}

bool Tree::all_visited(){
    for(auto b : v){
        if(!b) return false;
    }
    return true;
}

void Tree::assign_me(){
    int i=0;
    int degree=0;
    for(auto x: a){
        degree=x.second.size();
        if(degree==1){
            i=x.first;
            break;
        }
    }
    int ite_edge=1;
    int p=0;
    while (true){
        v[i-1]=true;
        vector<int> n = a[i];
        p=i;
        //cout<<"i="<<i<<"; p="<<p<<endl;
        for(auto val : n){
            //cout<<"neight >> val="<<val<<endl;
            if(v[val-1]) continue;
            else{
                i = val;
                v[i-1]=true;
                break;
            }
        }
        int p1 = min(p,i);
        int p2 = max(p,i);
        pair<int,int> p = {p1,p2};
        //cout<<"ite_edge="<<ite_edge<<"; e[p]"<<e[p]<<"; p1,p2="<<p1<<","<<p2<<endl;
        if(ite_edge%2==0){
            e[p]=5;
        }
        if(all_visited()){
            break;
        }
        ite_edge++;
    }
}

void Tree::check_edges(vector<pair<int,int>> vp){
    for(auto x : vp){
        //cout<<"u,v="<<x.first<<","<<x.second<<"; e[u,v]="<<e[x]<<endl;
        cout<<e[x]<<" ";
    }
    cout<<endl;
}

void solve(){
    int n;
    cin>>n;
    int n1, n2;
    vector<pair<int,int>> vp;
    Tree t(n);
    for(int i=0;i<n-1;i++){
        cin>>n1>>n2;
        t.add_edge(n1,n2);
        int p1=min(n1,n2);
        int p2=max(n1,n2);
        vp.push_back(make_pair(p1,p2));
    }
    if(t.is_poss()){
        t.assign_me();
        t.check_edges(vp);
    }else{
        cout<<-1<<endl;
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
    cin>>t;
    //t = 1;
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

