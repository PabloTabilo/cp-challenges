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

bool isNotDiv(ll p, ll c){
    if(max(c,p)%min(c,p)!=0) return true;
    return false;
}

void pv(vector<ll> v){
    int n=v.size();
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
    cout<<endl;
}

void solve(){
    ll n;
    cin>>n;
    ll i=2;
    vector<ll> res, best_res;
    ll t=n;
    int lim=sqrt(n), p;
    bool debugme=false;
    do{
        res.clear();
        while(n%i==0 && n>1){
            if(debugme) cout<<"i: "<<i<<"; n: "<<n<<endl;
            if(res.size()>1){
                if(isNotDiv(res.back(), i)){
                    // sacar a previous y no agregar current
                    res.pop_back(); 
                    break;
                }
            }
            res.push_back(i);
            n/=i;
            if(debugme) cout<<"n/=i: "<<n<<endl;
            if((n>1&&n%i!=0)||(n/i)%i!=0||n/i==1){
                if(isNotDiv(res.back(),n)){
                    res.pop_back();
                    break;
                }
                res.push_back(n);
                break;
            } 
        }
        n=t;
        if(res.size()>0){
            if(best_res.size()>0){
                if(debugme) pv(best_res);
                if(debugme) pv(res);
                if(best_res.size()<res.size()) best_res=res;
            }else best_res=res;
        }
        i++;
    }while(i<=lim);
    int m=best_res.size();
    if(m==0){
        m=1;
        best_res.push_back(t);
    }
    cout<<m<<endl;
    for(int i=0;i<m;i++) cout<<best_res[i]<<" ";
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

