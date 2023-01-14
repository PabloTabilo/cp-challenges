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

void solve(){
    int n;
    bool debug_me=false;
    cin>>n;
    vector<int>u(n);
    vector<int>s(n);
    priority_queue<pair<int,int>> sort_me;
    for(int i=0;i<n;i++) cin>>u[i];
    for(int i=0;i<n;i++) {
        cin>>s[i];
        sort_me.push(make_pair(s[i],u[i]));
    }
    map<int,vector<ll>> ans;
    ll p=-1;
    pair<int,int> x;
    while(!sort_me.empty()){
        x = sort_me.top();
        sort_me.pop();
        if(ans.find(x.second)==ans.end()){
            ans[x.second].push_back(x.first);
        }else{
            p = ans[x.second].back();
            ans[x.second].push_back((ll)x.first+p);
        }
    }
    vector<ll> ks(n+1,0);
    for(auto u : ans){
       vector<ll> acum=u.second;   
       int m=acum.size();
       if(debug_me) cout<<"u="<<u.first<<endl;
       if(debug_me) for(int i=0;i<m;i++) cout<<acum[i]<<" ";
       if(debug_me) cout<<endl;
       for(int k=1;k<=n;k++){
            if(k>m) break;
            if(debug_me) cout<<"k="<<k<<"; (m/k)="<<(m/k)<<"; (m/k)*k="<<(m/k)*k<<endl;
            int p=(m/k)*k;
            ks[k]+=acum[p-1];
       }
    }
    if(debug_me) cout<<"----------------------"<<endl;
    for(int i=1;i<=n;i++) cout<<ks[i]<<" ";
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

