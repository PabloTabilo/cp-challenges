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

void merge(int *a, int l, int m, int r, int *rP){
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1];
    int rL[n1];
    int R[n2];
    int rR[n2];
    for(int i=0;i<n1;i++){
        L[i] = a[l+i];
        rL[i] = rP[l+i];
    }
    for(int i=0;i<n2;i++){
        R[i] = a[m+1+i];
        rR[i] = rP[m+1+i];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            a[k] = L[i];
            rP[k] = rL[i];
            i++;
        }else{
            a[k] = R[j];
            rP[k] = rR[j];
            j++;
        }
        k++;
    }
    for(;i<n1;i++){
        a[k] = L[i];
        rP[k] = rL[i];
        k++;
    }
    for(;j<n2;j++){
        a[k] = R[j];
        rP[k] = rR[j];
        k++;
    }
}

void mergeSort(int * a, int l, int r, int * rP){
    if(l < r){
        int m = (l+r)/2;
        mergeSort(a, l, m, rP);
        mergeSort(a, m+1, r, rP);
        merge(a, l, m, r, rP);
    }
}

void pP(int *a, int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

void solve(){
    int n;
    cin>>n;
    int * o = new int[n];
    int * p = new int[n];
    int * rP = new int[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
        o[i] = p[i];
        rP[i] = i;
    }
    mergeSort(p, 0, n-1, rP);
    if(n == 2){
        pP(p, n);
    }else{
    int minDif = 1e9+1;
    int best_i = 0;
    int best_j = 0;
    for(int i=1;i<n;i++){
        if(abs(p[i-1] - p[i])<minDif){
            minDif = abs(p[i-1] - p[i]);
            best_i = i-1;
            best_j = i;
        }
    }
    debug(best_i);
    debug(best_j);
    debug(minDif);
    for(int i=best_j; i < n; i++)
        cout<<p[i]<<" ";
    for(int i=0; i<best_j;i++)
        cout<<p[i]<<" ";
    /*
    int minV = 1e9+1;
    int minIdx = 0;
    int maxV = 0;
    int maxIdx = 0;
    int bestAns = 0;
    for(int i = 0; i<n;i++){
        if(i != best_i && i != best_j){
            if(o[i] < minV){
                minV = o[i];
                minIdx = i;
            }
            if(o[i] > maxV){
                maxV = o[i];
                maxIdx = i;
            }
        }
    }
    bestAns = maxV - minV;
    debug(bestAns);
    cout<<o[best_i]<<" "<<o[maxIdx]<<" ";
    int i = 0;
    while(i < n){
        if(rP[i] != best_i && rP[i] != best_j && rP[i]!=maxIdx) cout<<p[i]<<" ";
        i++;
    }
    cout<<o[best_j]<<" ";
    */
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

