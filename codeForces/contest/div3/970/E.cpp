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

int min_ope(int * ho, int * he){
    // get min ope for AS
    int tot_e = 0;
    int max_e = 0;

    int tot_o = 0;
    int max_o = 0;
    for(int i=0;i<26;i++){
	tot_o += ho[i];
	max_o = max(max_o, ho[i]);
	tot_e += he[i];
	max_e = max(max_e, he[i]);
    }
    int min_op = (tot_o - max_o) + (tot_e - max_e);
    //cout << min_op << endl;	
    return min_op;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int he[26] = {0};
    int ho[26] = {0};
    for(int i=0;i<n;i++){
	if(i%2 == 0){
	    he[s[i]-'a']++;
	}else{
	    ho[s[i]-'a']++;
	}
    }
    int ans = INT_MAX;
    if(n % 2 == 0){
	ans = min_ope(ho, he);
    }else{
	for(int i=0;i<n;i++){
	    if(i%2 == 0){
		he[s[i]-'a']--;
		
	    }else{
		ho[s[i]-'a']--;
	    }
	    if( (i-1) >= 0){
		if((i-1)%2 == 0){
		    ho[s[i-1]-'a']++;
		}else{
		    he[s[i-1]-'a']++;
		}
	    }
	    int min_op = min_ope(ho, he);
	    ans = min(ans, 1 + min_op);
	    //cout << "i, s[i] = " << i << ", " << s[i] << endl;
	    //cout << "min_op = " << min_op << endl;
	    //cout << "ans = " << ans << endl;
	}
    }
    //cout << "ans = ";
    cout << ans << endl;
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

