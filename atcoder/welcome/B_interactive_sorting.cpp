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

// all differents? Yes: is Sorted!
bool ad(map<char,int> sm, int N){
    cout<<"all_diff"<<endl;
    vector<char> v(N+1,'.');
    for(auto x : sm){
        cout<<"k,v="<<x.first<<","<<x.second<<endl;
        if(v[x.second]=='.') v[x.second]=x.first;
        else return false;
    }
    return true;
}

// Apply changes to other values
void ac(map<char,int> & sm,vector<bool> v,char c1,char c2){
    for(auto x : sm){
        cout<<"ac >> x.first="<<x.first<<"; is v?:"<<v[x.first-'A']<<endl;
        if(x.first != c1 && x.first != c2 && v[x.first-'A']){
           if(x.second >= sm[c1]) sm[x.first]++;
        }
    }
}

string rec_c(map<char,vector<char>> cm, char c,int N, string res){
    //cout<<"try this letter: "<<c<<"; and at this recursive func res="<<res<<endl;
    res+=c;
    if(cm.find(c)==cm.end()){
        if(N-1<=0){
            return res;
        }else return "";
    }
    string a="";
    for(auto v : cm[c]){
         a=rec_c(cm,v,N-1,res); 
         if(a!="") break;
    }
    return a;
}

string check_me(map<char,vector<char>> cm, int N){
    string res="";
    for(auto u : cm){
        res = rec_c(cm,u.first,N,res);
        if(res != "") break;
    }
    return res;
}

void solve(){
    int N,Q;
    int p=1;
    char c1, c2, ans;
    string s;
    map<char,vector<char>> cm;
    cin>>N>>Q;
    vector<bool> v (N,false);
    for(int i=0;i<N;i++) {
        c1 = (char)('A'+i);
        s += c1;
    }
    string res="";
    while(p<N){
        for(int i=0;i+p<N;i++){
            c1=s[i];
            c2=s[i+p];
            if(v[c1-'A'] && !v[c2-'A']){
                char t=c1;
                c1=c2;
                c2=t;
            }
            v[c1-'A']=true;
            v[c2-'A']=true;
            cout<<"?"<<c1<<c2<<endl;
            cin>>ans;
            if(ans=='>'){
                cm[c1].push_back(c2);
            }else{ 
                cm[c2].push_back(c1);
            }
            res = check_me(cm,N);
            if(res!=""){
                p=N;
                break;
            }
        }
        p++;
    }
    reverse(res.begin(),res.end());
    cout<<"!"<<res<<endl;
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

