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

vector<pair<int,int>> bfs(int r1, int c1, int r2, int c2, vector<vector<int>> am, bool & existPath){
    int n=am.size();
    vector<vector<bool>> vis(n,vector<bool>(n,false));

    vector<pair<int,int>> ans;
    
    queue<int> qx;
    qx.push(r1-1);
    queue<int> qy;
    qy.push(c1-1);

    int vx[4] = {1,-1,0,0};
    int vy[4] = {0,0,1,-1};

    while(!qx.empty() && !existPath){
        int x = qx.front();
        int y = qy.front();
        qx.pop();
        qy.pop();
        if(vis[x][y]) continue;
        ans.push_back(make_pair(x+1,y+1));
        
        vis[x][y]=true;
        for(int i=0;i<4;i++){
           int cx=x+vx[i]; 
           int cy=y+vy[i]; 
           if(cx>=0 && cx<n && cy>=0 && cy<n){
                if(am[cx][cy]!=1 && !vis[cx][cy]){
                    if(cx==r2-1 && cy==c2-1) existPath=true;
                    qx.push(cx);
                    qy.push(cy);
                }
           }
        }
    }
    return ans;
}

void solve(){
    int n;
    int r1,c1;
    int r2,c2;
    cin>>n;
    cin>>r1>>c1;
    cin>>r2>>c2;
    vector<vector<int>> am(n,vector<int>(n,0));
    string str1;
    for(int i=0;i<n;i++){
        cin>>str1;
        for(int j=0;j<n;j++){
            am[i][j]=str1[j]-'0';
        }
    }
    bool existPath=false;
    ll cost=1e9+1;
    vector<pair<int,int>> g1 = bfs(r1,c1,r2,c2,am,existPath);
    if(!existPath){
        vector<pair<int,int>> g2 = bfs(r2,c2,r1,c1,am,existPath);
        int ng1=g1.size();
        int ng2=g2.size();
        ll diffx=0, diffy=0, local_cost=0;
        for(int i=0;i<ng1;i++){
            for(int j=0;j<ng2;j++){
                diffx = g1[i].first-g2[j].first;
                diffy = g1[i].second-g2[j].second;
                local_cost=diffx*diffx + diffy*diffy;
                cost=min(cost,local_cost);
            }
        }
    }
    if(cost==1e9+1) cost=0;
    cout<<cost<<endl;
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

