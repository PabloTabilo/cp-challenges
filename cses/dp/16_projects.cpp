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
#define sz(a) int((a).size())
 
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
	out << "[";
	fore(i, 0, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

/*----------------------------------------- utils maths or structures ----------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

int dfs(vector<vector<int>> projects, int max_days, int day, vector<int> & dp){
    if(day > max_days) return 0;
    
    if(dp[day] != -1) return dp[day];
    
    int max_profit = dfs(projects, max_days, day + 1, dp);

    for(int i=0;i<(int)projects.size();i++){
	int si = projects[i][0];
	int ei = projects[i][1];
	int pi = projects[i][2];

	if(si == day){
	    max_profit = max(max_profit, pi + dfs(projects, max_days, ei + 1, dp));	
	}
    }
    dp[day] = max_profit;
    return max_profit;
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> projects(n,vector<int>(3));
    int a, b, p;
    int max_days = -1;
    for(int i=0;i<n;i++){
	cin>>a>>b>>p;
	projects[i] = {a,b,p};
	max_days = max(max_days, b);
    }
    sort(projects.begin(), projects.end(), [](const auto & left, const auto & right){
	    return left[0] < right[0];
	    });
    //cout<<"[ "; for(auto & p : projects) cout<<"{"<<p[0]<<","<<p[1]<<","<<p[2]<<"} "; cout<<"]"<<endl;
    //vector<int> dp(max_days + 1, -1);
    //cout<<dfs(projects,max_days,1, dp)<<endl;
    vector<long long> dp(max_days + 2, 0);
    for(int day = max_days; day >= 1; day--){
	//cout<<"day = "<<day<<endl;
	dp[day] = dp[day + 1];
	for(const auto & project : projects){
	    int s = project[0];
	    int e = project[1];
	    int p = project[2];
	    if(s == day){
		//cout<<"the project s, e, p = "<<s<<","<<e<<","<<p<<" start on day = "<<day<<endl;
		dp[day] = max(dp[day], 1L * p + dp[e + 1]);
	    }
	}
	//cout<<"dp[day] = "<<dp[day]<<endl;
    }
    cout<<dp[1]<<endl;
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
    //cin.ignore();
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

