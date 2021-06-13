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

using namespace std;
//using namespace chrono;

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


/*---------------------------------------------------------------------------------------------------------------------------*/
void prPP(ll ** p, ll n, ll m){
    cout<<endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j < m; j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void solve(){
    int n, m;
    bool debugP = false;
    cin>>n>>m;
    ll ** dp = new ll *[n];
    for(int j=0;j<n;j++){
        dp[j] = new ll[m+1];
        for(int i=0;i<m+1;i++){
            dp[j][i] = 0;
        }
    }
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<n;j++){
        for(int i = 1; i<=m; i++){
            if(debugP) cout<<"a[j]: "<<a[j]<<"; j: "<<j<<"; i: "<<i<<endl;
            if(a[j] == 0){
                if(j > 0){
                    dp[j][i] = dp[j-1][i-1] + dp[j-1][i] + (i<m?dp[j-1][i+1]:0);
                    dp[j][i] %= MOD;
                }else{
                    dp[j][i] = 1;
                }
            }else{
                if(j > 0){
                    if(a[j]==i){
                        dp[j][i] = dp[j-1][i-1] + dp[j-1][i] + (i<m?dp[j-1][i+1]:0);
                        dp[j][i] %= MOD;
                    }else{
                        dp[j][i] = 0;
                    }
                }else{
                    dp[j][i] = (a[j]==i?1:0);
                }
            } 
            if(debugP) cout<<"dp[j][i] = "<<dp[j][i]<<endl;
        }
        if(debugP) cout<<"finish combinations"<<endl;
    }
    if(debugP) prPP(dp, n, m+1);
    ll res = 0;
    for(int i=1; i<=m;i++)
        res += dp[n-1][i]%MOD;
    cout<<res%MOD<<endl;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    //auto start1 = high_resolution_clock::now();
    // read & write file
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
    /*
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << endl;
#endif
*/
    return 0;
}

