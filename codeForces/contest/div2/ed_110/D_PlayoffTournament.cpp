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

bool debug_me=false;

void vdp(vector<int> dp, int n){
    for(int i=0;i<n+1;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
}

void solve(){
    int k;
    cin>>k;
    cin.ignore();
    int n = (1<<k)-1;
    string s;
    getline(cin, s);
    vector<int>dp(n+1);
    int w = (1<<(k-1));
    int i=0;
    for(;i<w;i++){
        if(s[i]=='?'){
            dp[i+1]=2;
        }else{
            dp[i+1]=1;
        }
    }
    while(i<n){
        if(s[i]=='?'){
            dp[i+1]=dp[i+1 - w] + dp[i+1 - w +1];
        }else if(s[i]=='1'){
            dp[i+1]=dp[i+1 - w +1];
        }else{
            dp[i+1]=dp[i+1 - w];
        }
        w--;
        i++;
    }
    if(debug_me){
        cout<<s<<endl;
        cout<<"init dp:"<<endl;
        vdp(dp,n);
    }
    int q, p;
    char c;
    cin>>q;
    while(q--){
        cin>>p>>c;
        s[p-1]=c;
        int w = n-p+1;
        if(debug_me){
            cout<<s<<endl;
            cout<<"w="<<w<<"; n="<<n<<"; p="<<p<<endl;
        }
        if(p <= (1<<(k-1))){
            if(c=='?'){
                dp[p] = 2;
            }else{
                dp[p] = 1;
            }
        }else{
            if(c=='?'){
                dp[p] = dp[p-w] + dp[p-w-1];
            }else if(c=='1'){
                dp[p] = dp[p-w];
            }else{
                dp[p] = dp[p-w-1];
            }
        }
        if(debug_me){
            cout<<"dp change on dp[p]"<<endl;
            vdp(dp,n);
        }
        // need expand to upper from p
        // log2
        int parent=p;
        while(parent<n){
            if(p%2==0) parent = p+(w/2);
            else parent = p+(w/2)+1;
            int l = parent - (w/2)-1;
            int r = parent - (w/2);
            if(debug_me) cout<<"parent="<<parent<<"; l="<<l<<"; r="<<r<<endl;
            if(s[parent-1]=='?'){
                dp[parent] = dp[l] + dp[r];
            }else if(s[parent-1]=='1'){
                dp[parent] = dp[r];
            }else{
                dp[parent] = dp[l];
            }
            p=parent;
            w/=2;
        }
        if(debug_me){
            cout<<"update to root"<<endl;
            vdp(dp,n);
        }
        cout<<dp[n]<<endl;
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    auto start1 = high_resolution_clock::now();
    // read & write file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
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

