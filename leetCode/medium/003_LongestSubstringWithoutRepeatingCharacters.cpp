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
bool debug = true;
int loopMe(string s, int i, int n, int r){
    int A[128] = {0};
    int A_i[128] = {0};
    int res = 0, c = 0;
    if(debug) cout<<"r: "<<r<<endl;
    while(i != n){
        int idx = s[i];
        A[idx]++;
        if(debug) cout<<"i: "<<i<<"; s[i]: "<<s[i]<<"; A[s[i]]: "<<A[idx]<<endl;
        if(A[idx] == 1){
            A_i[idx] = i;
            c++;
            res = max(res, c);
            i+=r;
            if(debug) cout<<"A_i[s[i]]: "<<A_i[s[i]]<<"; res: "<<res<<endl;
        }else{
            res = max(res, c);
            i = A_i[idx]+r;
            if(debug) cout<<"s[i]: "<<s[i]<<"; A_i[s[i]]+r: "<<A_i[idx]+r<<"; res: "<<res<<endl;
            c = 0;
            for(int  i=0;i<128;i++) A[i] = 0;
        }
    }
    return res;
}

class Solution{
    public:
        int lengthOfLongestSubstring(string s){
            int n = s.size();
            if (n==1||n==0) return n;
            int res1 = loopMe(s, 0, n, 1);
            //int res2 = loopMe(s, n-1, 0, -1);
            return res1;//max(res1, res2);
        }
};

void solve(){
    string s = "busvutpwmu"; // 7
    string s1 = "asjrgapa"; // 6
    string s2 = "dvdf"; // 3
    Solution sol;
    cout<<sol.lengthOfLongestSubstring(s)<<endl;
    cout<<sol.lengthOfLongestSubstring(s1)<<endl;
    cout<<sol.lengthOfLongestSubstring(s2)<<endl;
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

