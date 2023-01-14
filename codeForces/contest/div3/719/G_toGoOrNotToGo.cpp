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

int n, m, w;
bool debug_me=false;
void bfs(int s1, int s2, int w, vector<vector<int>> city,ll & reach,ll & portal){
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<int> qx;
    queue<int> qy;
    queue<ll> qc;
    qx.push(s1);
    qy.push(s2);
    qc.push(0);
    if(city[s1][s2]>0) portal=(ll)city[s1][s2]; 
    while(!qx.empty()){
        int x = qx.front();
        int y = qy.front();
        ll cost = qc.front();
        qx.pop();
        qy.pop();
        qc.pop();
        if(visited[x][y]) continue;
        visited[x][y] = true;
        if(city[x][y]==-1) continue;
        if(debug_me) cout<<"x,y,cost="<<x<<","<<y<<","<<cost<<endl;
        if(x+1<n && !visited[x+1][y]){
            qx.push(x+1);   
            qy.push(y);   
            qc.push(cost+w);   
            if(city[x+1][y]>0){
                ll nportal_cost=cost+w+(ll)city[x+1][y];
                if(portal > nportal_cost){
                    portal=nportal_cost; 
                }
            }
            if((x+1==n-1&&y==m-1)||(x+1==0&&y==0)){
                if(debug_me) cout<<"reach? x,y="<<x<<","<<y<<" -> "<<x+1<<","<<y<<endl;
                reach=cost+w;
            }
        }
        if(x-1>=0 && !visited[x-1][y]){
            qx.push(x-1);   
            qy.push(y);   
            qc.push(cost+w);   
            if(city[x-1][y]>0){
                ll nportal_cost=cost+w+(ll)city[x-1][y];
                if(portal > nportal_cost){
                    portal=nportal_cost; 
                }
            }
            if((x-1==n-1&&y==m-1)||(x-1==0&&y==0)){
                if(debug_me) cout<<"reach? x,y="<<x<<","<<y<<" -> "<<x-1<<","<<y<<endl;
                reach=cost+w;
            }
        }
        if(y+1<m && !visited[x][y+1]){
            qx.push(x);   
            qy.push(y+1);   
            qc.push(cost+w);   
            if(city[x][y+1]>0){
                ll nportal_cost=cost+w+(ll)city[x][y+1];
                if(portal > nportal_cost){
                    portal=nportal_cost; 
                }
            }
            if((x==n-1&&y+1==m-1)||(x==0&&y+1==0)){
                if(debug_me) cout<<"reach? x,y="<<x<<","<<y<<" -> "<<x<<","<<y+1<<endl;
                reach=cost+w;
            }
        }
        if(y-1>=0 && !visited[x][y-1]){
            qx.push(x);   
            qy.push(y-1);   
            qc.push(cost+w);   
            if(city[x][y-1]>0){
                ll nportal_cost=cost+w+(ll)city[x][y-1];
                if(portal > nportal_cost){
                    portal=nportal_cost; 
                }
            }
            if((x==n-1&&y-1==m-1)||(x==0&&y-1==0)){
                if(debug_me) cout<<"reach? x,y="<<x<<","<<y<<" -> "<<x<<","<<y-1<<endl;
                reach=cost+w;
            }
        }
    }
}
    
void solve(){
    cin>>n>>m>>w;
    vector<vector<int>> c(n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>c[i][j];
        }
    }
    // save portails && reach node
    // c = {x,y}
    // sort by cost
    ll res=LLONG_MAX;
    ll se=LLONG_MAX;
    ll sp=LLONG_MAX;
    ll es=LLONG_MAX;
    ll ep=LLONG_MAX;
    ll bp=LLONG_MAX;

    bfs(0,0,w,c,se,sp);
    if(debug_me) cout<<"---------------"<<endl;
    bfs(n-1,m-1,w,c,es,ep);
    if(debug_me) cout<<"se,sp,es,pe="<<se<<","<<sp<<","<<es<<","<<ep<<endl;
    if(sp!=LLONG_MAX && ep!=LLONG_MAX) bp = sp+ep;
    res = min(bp,se);
    if(res==LLONG_MAX) res=-1;
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

