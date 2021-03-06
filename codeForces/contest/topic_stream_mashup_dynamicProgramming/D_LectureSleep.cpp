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

void prA(vector<int> a, int n){
    cout<<endl;
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

void solve(){
    bool debug=false;
    int n;
    int k;
    cin>>n>>k;
    vector<int>a(n);
    vector<int>t(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>t[i];
    
    vector<int> acum(n);
    vector<int> p(n);
    vector<int> s(n);
    p[0] = a[0]*t[0];
    for(int i=1;i<n;i++) p[i] += a[i]*t[i] + p[i-1];
    s[n-1] = a[n-1]*t[n-1];
    for(int i=n-2;i>=0;i--) s[i] += a[i]*t[i] + s[i+1];
    acum[0] = a[0];
    for(int i=1;i<n;i++) acum[i] += a[i] + acum[i-1];

    ll res = p[n-1];
    ll suma1 = 0;
    if(debug) prA(p,n);
    if(debug) prA(s,n);
    if(debug) prA(acum,n);
    for(int i=0;i<=n-k;i++){
        if(debug) cout<<"i:"<<i<<endl;
        if(debug) cout<<"k:"<<i<<endl;
        if(i==0){
            if(i+k>=n) suma1 = acum[i+k-1];
            else suma1 = acum[i+k-1] + s[i+k]; 
        }else if(i+k>=n){
            suma1 = acum[i+k-1] - acum[i-1] + p[i-1]; 
        }else{
            suma1 = acum[i+k-1] - acum[i-1] + p[i-1] + s[i+k]; 
        }
        if(debug) cout<<suma1<<endl;
        res = max(res,suma1);
    }
     cout<<res<<endl;
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

