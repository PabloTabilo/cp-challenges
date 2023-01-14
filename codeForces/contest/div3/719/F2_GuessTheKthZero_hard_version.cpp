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
void bs(int l, int r, int k, int req){
    if(l==r){
        cout<<"! "<<l<<endl;
        fflush(stdout);
        return;
    }
    //if(req<=0) return;
    int m=(l+r)/2;
    cout<<"? "<<l<<" "<<m<<endl;
    fflush(stdout);
    int s=0;
    cin>>s;
    if(s==-1){
        exit(0);
        return;
    }
    if((m-l+1)-s>=k){
        bs(l,m,k,req-1);
    }else{
        bs(m+1,r,k-((m-l+1)-s),req-1);
    }
}

void update_me(int pos, int l, int r, map<pair<int,int>,int> & m){
    m[make_pair(l,r)]--;
    int mid=(l+r)/2;
    if(l != r){
        if(pos<=mid){
            update_me(pos,l,mid,m);
        }else{
            update_me(pos,mid+1,r,m);
        }
    }
}

void solve(){
    int n,t,k;
    int req=6e4;
    cin>>n>>t;
    map<pair<int,int>,int> mymap;
    while(t--){
        cin>>k;
        int l=1;
        int r=n;
        while(l!=r){
            int m=(l+r)/2;
            if(req<=0){
                break;
            }
            pair<int,int> p = {l,m};
            if(mymap.count(p)==0){
                cout<<"? "<<l<<" "<<m<<endl;
                req--;
                fflush(stdout);
                int s=0;
                cin>>s;
                if(s==-1){
                    exit(0);
                    break;
                }
                mymap[p]=(m-l+1)-s;
            }
            if(mymap[p]>=k){
                r=m;
            }else{
                l=m+1;
                k-=mymap[p];
            }
        }
        cout<<"! "<<l<<endl;
        fflush(stdout);
        update_me(l,1,n,mymap);
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

