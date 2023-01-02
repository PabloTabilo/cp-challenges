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

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    map<int, vector<int>> m;
    bool debugme=false;
    for(int i=0;i<n;i++){
        cin>>a[i];
        m[a[i]].push_back(i);
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        m[b[i]].push_back(i);
    }
    map<int,int> f;
    vector<int> t;
    int dl, dr, d;
    int res = -1;
    for(auto k : m){
        t = k.second;
        if(debugme) cout<<"k.first: "<<k.first<<"; k.second[0]: "<<k.second[0]<<"; k.second[1]: "<<k.second[1]<<endl;
        if(t[0]>t[1]){
            dl = t[1]-t[0];// 1, 3, 2, 4 -> 3, 2, 4, 1
            dr = n-t[0]+t[1];// 1, 3, 2, 4 -> 4, 1, 3, 2 -> 2, 4, 1, 3 -> 3, 2, 4, 1
        }else if(t[0]<t[1]){
            dr = t[1]-t[0];
            dl = (t[0] + (n-t[1]))*-1;
        }else{
            dr=0;
            dl=0;
        }
        if(debugme) cout<<"dl: "<<dl<<"; dr: "<<dr<<endl;
        if(abs(dl)<abs(dr)) d=dl;
        else d=dr;
        f[d]++;
        if(debugme) cout<<"d: "<<d<<"; f[d]: "<<f[d]<<endl;
        res=max(res,f[d]);
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

