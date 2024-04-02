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

void p2v(vector<vector<char>> v){
    for(auto x : v){
	for(auto c : x){
	    cout<<c<<",";
	}
	cout<<endl;
    }
}

void solve(){
    vector<vector<char>> m(3, vector<char>(3,'.'));
    for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
	    cin>>m[i][j];
	}
    }
    //p2v(m);

    char ansc = '.';
    for(int i=0;i<3 && ansc == '.';i++){
	for(int j=0;j<3 && ansc == '.';j++){
	    char p = m[i][j];
	    //cout<<"i,j,m[i][j] = "<<i<<","<<j<<","<<m[i][j]<<endl;
	    ansc = '.';
	    // COLUMN MOVE
	    // down move
	    if(i+1<3 && p == m[i+1][j]){
		// mid
		if(i-1>=0 && p == m[i-1][j]){
		    ansc=p;
		    break;
		}
		// most down
		if(i+2<3 && p == m[i+2][j]){
		    ansc=p;
		    break;
		}
	    }
	    // up move
	    if(i-1 >= 0 && p == m[i-1][j]){
		// most up
		if(i-2 >= 0 && p == m[i-2][j]){
		    ansc=p;
		    break;
		}
	    }
	    // ROW MOVE
	    // right
	    if(j+1 < 3 && p == m[i][j+1]){
		// mid
		if(j-1>=0 && p == m[i][j-1]){
		    ansc=p;
		    break;
		}
		// most right
		if(j+2<3 && p == m[i][j+2]){
		    ansc=p;
		    break;
		}
	    }
	    // left
	    if(j-1 >= 0 && p == m[i][j-1]){
		// most left
		if(j-2>=0 && p == m[i][j-2]){
		    ansc=p;
		    break;
		}
	    }
	    // DIAGONAL MOVE DOWN-RIGHT
	    if(i+1<3 && j+1<3 && m[i+1][j+1] == p){
		// mid
		if(i-1>=0 && j-1>=0 && m[i-1][j-1] == p){
		    ansc=p;
		    break;
		}
		if(i+2<3 && j+2<3 && m[i+2][j+2] == p){
		    ansc=p;
		    break;
		}
	    }
	    // DIAGONAL MOVE UP-LEFT
	    if(i-1>=0 && j-1>=0 && m[i-1][j-1] == p){
		if(i-2>=0 && j-2>=0 && m[i-2][j-2] == p){
		    ansc=p;
		    break;
		}
	    }
	    
	    // DIAGONAL MOVE DOWN-LEFT
	    if(i+1<3 && j-1>=0 && m[i+1][j-1] == p){
		// mid
		if(i-1>=0 && j+1<3 && m[i-1][j+1] == p){
		    ansc=p;
		    break;
		}
		if(i+2<3 && j-2>=0 && m[i+2][j-2] == p){
		    ansc=p;
		    break;
		}
	    }
	    // DIAGONAL MOVE UP-LEFT
	    if(i-1>=0 && j+1<3 && m[i-1][j+1] == p){
		if(i-2>=0 && j+2<3 && m[i-2][j+2] == p){
		    ansc=p;
		    break;
		}
	    }
	}
    }
    //
    // 0,0 0,1 0,2
    // 1,0 1,1 1,2
    // 2,0 2,1 2,2
    if(ansc == '.'){
	cout<<"DRAW";
    }else{
	cout<<ansc;
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

