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

class Graph{
public:
    map<int, vector<int>> adj;
    Graph(int nodes){
	for(int i=1;i<=nodes;i++){
	    adj[i].push_back(-1);
	    adj[i].pop_back();
	}
    }

    void addEdge(int n1, int n2){
	adj[n1].push_back(n2);
	adj[n2].push_back(n1);
    }

    string howami(){
	// 1. bus -> {1, 2, 2, ..., 2, 2, 1}
	// 2. ring -> {2, 2, 2, ..., 2, 2, 2}
	// 3. start -> {1, 1, 1, 1,..., 1, 1, k}
	// 4. unknow 
	int d;
	vector<int> v(3,0); //0,1,2
	for(auto x : adj){
	    d = x.second.size();
	    //cout<<x.first<<" -> "<<x.second.size()<<endl;
	    if(d <= 2) v[d]++;
	    else v.push_back(d);
	}
	
	// exists 0 -> unknow
	if(v[0]>0) return "unknown";
	
	if(v.size()<=3){
	    // bus or ring
	    if(v[1]>0) return "bus";
	    return "ring";
	}else{
	   // start or unknow 
	   if(v[1]>0 && v[2]==0 && v.size()==4) return "star";
	   return "unknown";
	}
    }
};

void solve(){
    int n, m;
    cin>>n>>m;
    Graph g(n);
    int n1, n2;
    for(int i=0;i<m;i++){
	cin>>n1>>n2;
	g.addEdge(n1, n2);
    }
    string res = g.howami();
    cout<<res<<" topology"<<endl;
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
    //cin.ignore();
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

