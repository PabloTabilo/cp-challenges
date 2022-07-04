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

void sort_lexi(string & v){
    vector<char> r(3);
    for(int i=0;i<v.length();i++){
        r[v[i]-65]=v[i];
    }
    string s1(1,r[0]);
    string s2(1,r[1]);
    string s3(1,r[2]);
    if(r[0]+0==0) s1="";
    if(r[1]+0==0) s2="";
    if(r[2]+0==0) s3="";
    v = s1+s2+s3;
}

void solve(){
    int n;
    int c;
    int INF = 10e6;
    string v;
    cin>>n;
    unordered_map<string,int> um;
    um["A"] = INF;
    um["B"] = INF;
    um["C"] = INF;
    um["AB"] = INF;
    um["AC"] = INF;
    um["BC"] = INF;
    um["ABC"] = INF;
    
    for(int i=0;i<n;i++){
        cin>>c>>v;
        //cout<<"Input: "<<v<<","<<c<<endl;
        sort_lexi(v);
        //cout<<"n_v = "<<v.length()<<endl;
        //cout<<"post Sorting lexi: "<<v<<","<<c<<endl;
        //cout<<"Get last um[v]="<<um[v]<<endl;
        um[v] = min(um[v],c);
        //cout<<"unordered_map: (k,v1)>>("<<v<<","<<um[v]<<")"<<endl;
    }
    int a_b_c = um["A"]+um["B"]+um["C"];
    debug(a_b_c);
    int ab_c = um["AB"]+um["C"];
    debug(ab_c);
    int ac_b = um["AC"]+um["B"];
    debug(ac_b);
    int bc_a = um["BC"]+um["A"];
    debug(bc_a);
    int abc = um["ABC"];
    debug(abc);
    int ab_ac = um["AB"]+um["AC"];
    debug(ab_ac);
    int ab_bc = um["AB"]+um["BC"];
    debug(ab_bc);
    int ac_bc = um["AC"]+um["BC"];
    debug(ac_bc);
    int res = min(abc, min(a_b_c, min(ab_c, min(ac_b, min(bc_a, min(ab_ac, min(ab_bc,ac_bc)))))));
    debug(res);
    if(res >= INF) res=-1;
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

