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
void pv(vector<vector<int>> v, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void solve(){
    string s;
    getline(cin,s);
    int n=s.length();
    vector<vector<int>>dp(n, vector<int>(n,0));
    int j, res=0;
    bool debugme=false;
    for(int i=0;i<n;i++) dp[i][i]=1;
    for(int gap=2;gap<=3;gap++){
        for(int i=0;i<=n-gap;i++){
            j=gap+i-1;
            if(i==j-1){
                dp[i][j]=(s[i]==s[j] ? 1:0);
            }else{
                dp[i][j]=(s[i]==s[j] && dp[i+1][j-1] ? 1:0);
            }
        }
    }
    if(debugme) pv(dp,n);
    vector<bool> u(n,true);
    for(int g=2; g<=3;g++){
        for(int i=0;i<=n-g;i++){
            j=g+i-1;
            if(dp[i][j]==1&&u[i]&&u[j]){
                if(g==3){
                    if(dp[i][j-1]==1&&dp[i+1][j]==1){
                        dp[i][j-1]=-1;
                        dp[i+1][j]=-1;
                        res++;
                    }else if(i+1<n && j+1<n && dp[i+1][j+1]==1){
                        dp[i+1][j+1]=-1;
                        u[i+1]=false;
                        u[j+1]=false;
                        res++;
                    }
                    u[j-1]=false;
                }
                res++;
                dp[i][j]=-1;
                u[i]=false;
                u[j]=false;
            }
        }
        if(debugme){
            if(g==3) cout<<"g=3"<<endl;
            else cout<<"g=2"<<endl;
            pv(dp,n);
        }
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
    cin>>t;
    cin.ignore();
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

