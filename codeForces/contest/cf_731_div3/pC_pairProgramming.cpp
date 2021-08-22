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
    int k ,n, m;
    bool debug = false;
    cin>>k>>n>>m;
    vector <int> A(n);
    vector <int> B(m);
    vector <int> C;
    for(int i = 0; i<n;i++){
        cin>>A[i];
    }
    for(int i = 0; i<m;i++){
        cin>>B[i];
    }
    int i = 0;
    int j = 0;
    bool pos = true;
    while(i + j < n + m && pos){
        if (debug) cout<<"A[i]: "<<A[i]<<"; i: "<<i<<"; B[j]: "<<B[j]<<"; j: "<<j<<endl;
        if (debug) cout<<"k: "<<k<<"; pos: "<<pos<<"; n + m: "<<n+m<<"; i+j: "<<i+j<<endl;
        if(A[i] > k && B[j] > k){
            pos = false;
        }else if(A[i] > k && i < n && j >= m){
            pos = false;
        }else if(A[i] <= k && i < n && j >= m){
            C.push_back(A[i]);
            if(A[i] == 0) k++;
            i++;
        }
        else if(B[i] > k && i >= n && j < m){
            pos = false;
        }
        else if(B[j] <= k && i >= n && j < m){
            C.push_back(B[j]);
            if(B[j] == 0) k++;
            j++;
        }
        else if(i < n && A[i] < B[j] && A[i]<= k){
            C.push_back(A[i]);
            if(A[i] == 0) k++;
            i++;
        }else if(j < m && B[j]<=k){
            C.push_back(B[j]);
            if(B[j]==0) k++;
            j++;
        }else{
            pos = false;
        }
        if(debug) cout<<"--------------------------"<<endl;
    }
    if(!pos) cout<<-1;
    else{
        int nC = C.size();
        for(int i = 0; i<nC; i++) cout<<C[i]<<" ";
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

