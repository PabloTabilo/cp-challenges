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

struct myComp
{
    int operator()(const tuple<int,int> & tuple1, const tuple<int,int> & tuple2){
        if(get<0>(tuple1)==get<0>(tuple2)){
            if(get<1>(tuple1)>=get<1>(tuple2)) return true;
            return false;
        }
        return get<0>(tuple1)>=get<0>(tuple2);
    }
};

int pPQ(priority_queue<tuple<int,int>, vector<tuple<int,int>>, myComp> pq1){
    bool pos = true;
    int lA = -1;
    int lB = -1;
    int cA, cB;
    int finalDay = -1;
    //cout<<endl;
    while(!pq1.empty()){
        tuple<int,int> topVal = pq1.top();
        //cout<<get<0>(topVal)<<","<<get<1>(topVal)<<endl;
        if(lA+lB == -2){
            lA = get<0>(topVal);
            lB = get<1>(topVal);
            if(finalDay <= lB) finalDay = lB;
            else finalDay = lA;
        }else{
            cA = get<0>(topVal);
            cB = get<1>(topVal);
            if(finalDay <= cB) finalDay = cB;
            else finalDay = cA;
            lA = cA;
            lB = cB;
        }
        pq1.pop();
    }
    //cout<<endl;
    return finalDay;
}

void solve(){
    int n;
    cin>>n;
    priority_queue<tuple<int,int>, vector<tuple<int,int>>, myComp> pq1;
    int a, b;
    tuple<int, int> t1;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        t1 = make_tuple(a,b);
        pq1.push(t1);
    }
    int res = pPQ(pq1);
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

