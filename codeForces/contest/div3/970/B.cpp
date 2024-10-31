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

int lim = 200001;
vector<bool> is_square(lim, false);

void fill_v(){
    for(int i = 2; i*i < lim; i++){
	is_square[i*i] = true;
    }
}


void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(!is_square[n]){
	cout << "No" << endl;
	return;
    }else{
	int sq = 2;
	while(sq*sq != n){
	    sq++;
	}
	int num = 0;
	// first row
	for(int i=0;i<sq;i++){
	    num += (s[i]-'0');
	}
	if(num != sq){
	    cout << "No" << endl;
	    return;
	}
	// last row
	num = 0;
	for(int i=n-1;i>=n-sq;i--){
	    num += (s[i]-'0');
	}
	if(num != sq){
	    cout << "No" << endl;
	    return;
	}
	// intermediate rows
	for(int i=sq;i<n-sq;i+=sq){
	    num = 0;
	    for(int j=0;j<sq;j++){
		char x = s[i+j];
		num += (x - '0');
	    }
	    if(num != 2){
		cout << "No" << endl;
		return;
	    }
	}
	cout<< "Yes" << endl;

    }
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
    fill_v();
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

