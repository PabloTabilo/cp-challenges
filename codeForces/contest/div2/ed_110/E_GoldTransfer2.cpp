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

/*--------- debug mode -----------*/
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

/*-------- some cout modifications ---------*/

#define fore(i,l,r) for(int i=int(l);i<int(r);i++)

/*----------------------------------------- utils maths or structures ----------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

void solve(){
    int q, a, c;
    int n = 3*1e5+1;
    const int LOG = 20;
    
    vector<pair<int,int>> rt(n,make_pair(-1,-1));
    vector<vector<int>> p(LOG);
    
    cin>>q>>a>>c;

    rt[0]=make_pair(a,c);
    fore(i,0,LOG) p[i].resize(q+1); 
    fore(i,0,LOG) p[i][0]=0;
    rt.resize(q+1);

    int ask, pi, vi, wi;
    int id=1;
    int k;
    int ag; // amount of gold
    ll mm; // min money
    while(q--){
        cin>>ask;
        if(ask==1){
            cin>>pi>>a>>c;
	    rt[id]=make_pair(a,c);
	    p[0][id]=pi;
	    fore(lg,1,LOG)
		p[lg][id]=p[lg-1][p[lg-1][id]];
        }else{
            cin>>vi>>wi;
	    ag=0;
	    mm=0;
	    while(wi>0 && rt[vi].first>0){
		k=vi;
		for(int lg=LOG-1;lg>=0;lg--){
		    if(rt[p[lg][k]].first>0){
			k=p[lg][k];
			break;
		    }
		}
		int mn = min(wi,rt[k].first);

		rt[k].first -= mn;
		wi -= mn;

		ag += mn;
		mm += mn * (1ll) * rt[k].second;

	    }
            cout<<ag<<" "<<mm<<endl;
        }
        id++;
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

