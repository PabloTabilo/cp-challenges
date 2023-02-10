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

void pv(vector<int> v){
    int n = v.size();
    for(int i=0;i<n;i++){
	cout<<v[i]<<" ";
    }
    cout<<endl;
}

ll extremes(vector<int> a, int n, int k, bool debug_me){
    ll score=0;
    int i=0;
    int j=n-1;
    while(k--){
	if(debug_me) cout<<"k="<<k<<"; i="<<i<<"; a[i]="<<a[i]<<"; a[j]="<<a[j]<<endl;
	score+=(ll)(a[j]/a[i]);
	if(debug_me) cout<<"score="<<score<<endl;
	i++;
	j--;
    }
    j++;
    while(i<j){
	score+=(ll)a[i];
	i++;
    }
    if(debug_me) cout<<"final i="<<i<<endl;
    return score;
}

ll only_greater(vector<int> a, int n, int k, bool debug_me){
    ll score=0;
    int i=0;
    while(k--){
	if(debug_me) cout<<"k="<<k<<"; i="<<i<<"; a[i]="<<a[i]<<"; a[i+1]="<<a[i+1]<<endl;
	score+=(ll)(a[i+1]/a[i]);
	if(debug_me) cout<<"score="<<score<<endl;
	i+=2;
    }
    while(i<n){
	score+=(ll)a[i];
	i++;
    }
    if(debug_me) cout<<"final i="<<i<<endl;
    return score;
}

ll only_lows(vector<int> a, int n, int k, bool debug_me){
    ll score=0;
    int i=n-1;
    while(k--){
	if(debug_me) cout<<"k="<<k<<"; i="<<i<<"; a[i]="<<a[i]<<"; a[i-1]="<<a[i-1]<<endl;
	score+=(ll)(a[i]/a[i-1]);
	if(debug_me) cout<<"score="<<score<<endl;
	i-=2;
    }
    while(i>=0){
	score+=(ll)a[i];
	i--;
    }
    if(debug_me) cout<<"final i="<<i<<endl;
    return score;
}

ll from_mid(vector<int> a, int n, int k, bool debug_me){
    ll score=0;
    int i=k-1;
    int j=2*k-1;
    int kt=k;
    while(kt--){
	if(debug_me) cout<<"k="<<k<<"; i="<<i<<"; a[i]="<<a[i]<<"; a[j]="<<a[j]<<endl;
	score+=(ll)(a[j]/a[i]);
	if(debug_me) cout<<"score="<<score<<endl;
	i--;
	j--;
    }
    if(debug_me) cout<<"sum next k to n; k,n="<<k<<","<<n<<endl;
    i = 2*k;
    while(i<n){
	if(debug_me) cout<<"i="<<i<<"; a[i]="<<a[i]<<endl;
	score+=(ll)a[i];
	i++;
    }
    return score;

}

void solve(){
    int n, k;
    bool debug_me=false;
    cin>>n>>k;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end(),greater<int>());
    if(debug_me) pv(a);
    //ll score_a = extremes(a,n,k,debug_me);
    //ll score_b = only_greater(a,n,k,debug_me);
    //ll score_c = only_lows(a,n,k,debug_me);
    ll score_d = from_mid(a,n,k,debug_me);
    //ll score=min(score_a, min(score_b,min(score_c, score_d)));
    cout<<score_d<<endl;
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

