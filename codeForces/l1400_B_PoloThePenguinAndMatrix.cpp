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

void printV(vector<vector<int>> a, int n, int m){
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

int dfs(vector<vector<int>> & a, int n, int m, int & limit, int d, int e,int i, int j){
    if(i < 0||j < 0||i >= n||j >= m) return 1e9;
    cout<<"analyze->a[i][j]="<<a[i][j]<<"; i,j="<<i<<","<<j<<endl;
    if(a[i][j] > e ) a[i][j] -= d;
    if(a[i][j] < e) a[i][j] += d;
    if(a[i][j]==e && limit <= 0) return 0;
    limit -= 1;
    return 1 + min(dfs(a,n,m,limit,d,e,i-1,j), 
                    min(
                        dfs(a,n,m,limit,d,e,i+1,j),
                            min( 
                                dfs(a,n,m,limit,d,e,i,j+1), 
                                dfs(a,n,m,limit,d,e,i,j-1)
                                )
                        )
                );
}

void copyMe(vector<vector<int>> & a, vector<vector<int>> & t, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) t[i][j] = a[i][j];
    }
    
}

void solve(){
    int n, m, d;
    set<int> s1;
    cin>>n>>m>>d;
    //vector<vector<int>> a(n, vector<int>(m,0));
    vector<int> b(n*m);
    //vector<vector<int>> t(n, vector<int>(m,0));
    //vector<vector<int>> dp(n, vector<int>(m,0));
    bool pos = true;
    int fm = -1;
    for(int i=0;i<n*m;i++){
        cin>>b[i];
        if(i==0) fm = b[i]%d; 
        if(b[i]%d!=fm)pos=false;
        //for(int j=0;j<m;j++){ 
           // cin>> a[i][j];
          //  t[i][j] = a[i][j];
         //   if(a[i][j]%d!=0) pos=false;
         //   s1.insert(a[i][j]);
        //}
    }
    //printV(a,n,m);
    int best=1e7+1;
    if(pos){
    //set<int, greater<int> >::iterator itr;
    //cout << "\nThe set s1 is : \n"; 
    //int e;
    //int limit = n*m;
/*
    for (itr = s1.begin(); itr != s1.end(); itr++) { 
        e = *itr;
        int best_ans=1e7;
        // can start from any i,j pair
        cout<<"e="<<e<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<"start point: i,j="<<i<<","<<j<<"; a[i][j]="<<a[i][j]<<endl;
                int ans = dfs(a,n,m, limit,d,e,i,j);
                cout<<"ans="<<ans<<endl;
                copyMe(a,t,n,m);
                best_ans = min(best_ans, ans);
                cout<<"best_ans=min(ans)="<<best_ans<<endl;
                limit = n*m;
            }
        } 
        cout<<"-------------------"<<endl;
        best = min(best, best_ans);
    }
*/
    sort(b.begin(), b.end());
    debug(b);
    int cand1 = b[(n*m)/2];
    int cand2 = b[(n*m)/2 - 1];
    int ac1 = 0;
    int ac2 = 0;
    debug(cand1);
    debug(cand2);
    for(int i=0;i<n*m;i++){
        ac1+=abs(b[i] - cand1);
        ac2+=abs(b[i] - cand2);
    }
    best = min(ac1,ac2) / d;
    }else best=-1;
    cout<<best<<endl; 
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    auto start1 = high_resolution_clock::now();
    // read & write file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
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

