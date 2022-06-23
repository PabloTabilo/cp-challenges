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

void dfs_root(vector<vector<int>> & g, vector<int> & dp, vector<int> & a, int v, int prev=-1){
    dp[v] = a[v];
    for(auto to : g[v]){
        if(to == prev) continue; // not comeback
        dfs_root(g, dp, a, to, v);
        dp[v] += max(dp[to],0);
    }
}

void dfs_reroot(vector<vector<int>> & g, vector<int> & dp, vector<int> & ans, int v, int prev=-1){
    ans[v] = dp[v];
    debug("in");
    debug(v);
    for(auto to : g[v]){
        debug(to);
        if(to == prev) continue; // not comeback
        dp[v] -= max(0,dp[to]);
        dp[to] += max(0,dp[v]);
        debug(dp);
        debug("next-child");
        dfs_reroot(g, dp, ans, to, v);
        dp[to] -= max(0,dp[v]);
        dp[v] += max(0,dp[to]);
        debug("comeback to old dp");
        debug(dp);
        debug(v);
        debug(to);
        debug("-- finish --")
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> ans(n,0);
    vector<int> dp(n);
    vector<vector<int>> g(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i] == 0) a[i] = -1;
    }
    int x, y;
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }

    dfs_root(g,dp,a,0);
    debug(a);
    debug(dp);
    dfs_reroot(g,dp,ans,0);

    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;
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

