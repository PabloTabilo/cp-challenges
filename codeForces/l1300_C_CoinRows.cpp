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

#define VAL 10001

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
// https://codeforces.com/problemset/problem/1555/C

void view_vec(vector<vector<int>> v, int m){
    cout<<"----------------------------------------"<<endl;
    for(int i=0; i<2;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------------------------------"<<endl;
}

int get_sum_corner(vector<vector<int>> a, int m, vector<vector<int>>t){
    for(int i=0; i<2;i++){
        for(int j=0;j<m;j++) if(t[i][j]==-1 && t[i+1][j]==-1) return a[i][j];
    }
    return 0;
}

int cc(vector<vector<int>> & dp,vector<vector<int>> & a, int x, int y, int m, vector<vector<int>> & trackme, int track){
    //cout<<"x="<<x<<"; y="<<y<<endl;
    if(x==1 && y==m-1) return a[x][y];
    else if(x>1) return VAL*-1;
    else if(y>=m) return VAL*-1;
    else{
        int d=0;
        int c1=cc(dp,a,x+1,y,m,trackme,track);
        int c2=cc(dp,a,x,y+1,m,trackme,track);
        //cout<<"a[x][y]="<<a[x][y]<<endl;
        //cout<<"c1="<<c1<<endl;
        //cout<<"c2="<<c2<<endl;
        if(c1>c2){
            d=c1;
            trackme[x+1][y]+=track;
        }else if(c1==c2){
            d=c1;
            trackme[x+1][y]+=track;
            trackme[x][y+1]+=track;
        }else{
            d=c2;
            trackme[x][y+1]+=track;
        }
        //cout<<"d="<<d<<endl;
        //cout<<"a[x][y]+d="<<a[x][y]+d<<endl;
        if(dp[x][y]!=a[x][y]) return dp[x][y];
        dp[x][y]+=d;
        return dp[x][y];
    }
}

void get_route(vector<vector<int>> dp, vector<vector<int>> & t, int m, int x, int y){
    if(x+1>=2 && y+1>=m){
        t[x][y]=-1;
    }else if(x+1>=2){
        t[x][y]=-1;
        get_route(dp,t,m,x,y+1);
    }else if(y+1>=m){
        t[x][y]=-1;
        get_route(dp,t,m,x+1,y);
    }else{
        t[x][y]=-1;
        int c1=dp[x+1][y];
        int c2=dp[x][y+1];
        if(c1 >= c2){
            get_route(dp,t,m,x+1,y);
        }else{
            get_route(dp,t,m,x,y+1);
        }
    }
}

void solve(){
    int m;
    cin>>m;
    vector<vector<int>> a(2,vector<int>(m,0));
    vector<vector<int>> dp(2,vector<int>(m,0));
    vector<vector<int>> trackme(2,vector<int>(m,0));
    vector<vector<int>> t(2,vector<int>(m,0));
    for(int i=0;i<2*m;i++){
        if(i<m){
            cin>>a[0][i];
            dp[0][i]=a[0][i];
        }else{ 
            cin>>a[1][i-m];
            dp[1][i-m]=a[1][i-m];
        }
    }
    int costA = cc(dp,a,0,0,m,trackme,-1);
    //cout<<"costA="<<costA<<endl;
    //view_vec(trackme,m);
    get_route(dp,t,m,0,0);
    //view_vec(dp,m);
    view_vec(t,m);
    //int costB = cc(a,0,0,m,trackme,1);
    //view_vec(a,m);
    //view_vec(trackme,m);
    //cout<<"costB="<<costB<<endl;
    //view_vec(trackme,m);
    int c = get_sum_corner(a,m,t);
    if(m==1) c=0;
    int r1s=0;
    int r2s=0;
    for(int i=0;i<m;i++){
        if(t[0][i]==0) r1s+=a[0][i];
        if(t[1][i]==0) r2s+=a[1][i];
    }
    if(r1s==0) r1s=VAL;
    if(r2s==0) r2s=VAL;
    //cout<<"c="<<c<<endl;
    //cout<<"r1s="<<r1s<<endl;
    //cout<<"r2s="<<r2s<<endl;
    cout<<min(c,min(r1s,r2s))<<endl;
    // Ya tengo la ruta opt
    // 1. Saco score con val dif a ruta opt
    // entra a while
    // donde saca el min score
    // tal que voy quitando cuadrantes factibles
    // de la solucion opt
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

