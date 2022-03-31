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

void viewArr(int a[8][8], int n){
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int myres(int a[8][8], int n){
    int res = 0;
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n;j++)
            res+=a[i][j];
    }
    return res;
}

void solve(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int a[8][8] = {0};
    fill(&a[0][0],&a[0][0]+sizeof(a)/sizeof(a[0][0]), 1);
    int x1 = s1[0]-'a';
    int y1 = s1[1]-'1';
    for(int i=0;i<8;i++) a[x1][i]=0;
    for(int i=0;i<8;i++) a[i][y1]=0;
    int posx [9] = {-2, -2, 2, 2, 1, -1, 1, -1, 0};
    int posy [9] = {1, -1, 1, -1, 2, 2, -2, -2, 0};
    int x2 = s2[0]-'a';
    int y2 = s2[1]-'1';
    for(int i=0;i<9;i++){
        int x = x2 + posx[i];
        int y = y2 + posy[i];

        int xo = x1 + posx[i];
        int yo = y1 + posy[i];
        if(x < 8 && x >= 0 && y < 8 && y>=0) a[x][y] = 0;
        if(xo < 8 && xo >= 0 && yo < 8 && yo>=0) a[xo][yo] = 0;
    }
    cout<<myres(a, 8)<<endl;
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

