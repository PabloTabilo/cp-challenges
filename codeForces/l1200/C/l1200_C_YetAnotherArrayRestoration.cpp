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

void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    int diff = y-x;
    bool debugme = false;
    // 5 -> 10 -> 15 -> ...
    // 9 -> 3 (prime)
    // Cuantos elementos puedo colocar entre x e y
    // tengo q ir a por los primos
    // Si es primo, no puedo colocar menos q el
    // solo multiplicar
    int t=-1, best_t=-1, best_d=-1;
    int start = x;
    for(int d=1;d<=diff;d++){
        if(diff%d) continue;
        t=diff/d;
        if(t < n){
            if(debugme) cout<<"t<=n ---> d="<<d<<"; t="<<t<<"; diff="<<diff<<"; x="<<x<<"; y="<<y<<endl;
            // is Possible
            if(debugme) cout<<"** on while **"<<endl;
            while(y-t*d > 0 && t > best_t && t<n){
                if(debugme) cout<<"t="<<t<<"; n="<<n<<"; y-t*d="<<y-t*d<<endl;
                if(t>n){
                    if(debugme) cout<<"------ BREAK -------"<<endl;
                    break;
                }
                if(start >= y-t*d){
                    start = y-t*d;
                    best_t=t;
                    best_d=d;
                    if(debugme) cout<<"start="<<start<<"; best_t="<<t<<"; best_d="<<d<<endl;
                    if(debugme) cout<<"--------------------"<<endl;
                }
                t++;
            }
        }
    }

    if(debugme) cout<<"start="<<start<<"; best_t="<<best_t<<"; best_d="<<best_d<<endl;
    for(int i=0;i<n;i++){
        cout<<start + i*best_d<<" ";
    }
    cout<<endl;

    // Tengo q tender a ir a hacia abajo
    // check if is prime
    // is prime -> all is ok
    // not prime? search prime or factors

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

