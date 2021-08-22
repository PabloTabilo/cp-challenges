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
    int a[26] = {0};
    bool debug = false;
    string s;
    getline(cin, s);
    int n = s.size();
    bool impos = false;
    char maxC = 0;
    for(int i=0;i<n;i++){
        a[s[i]-'a']++;
        if(a[s[i]-'a'] > 1) impos = true;
        maxC = max(maxC, s[i]);
    }
    if(debug)cout<<"maxC: "<<maxC<<endl;
    if(!impos){
        for(int i = maxC-'a'; i>=0;i--){
            if(a[i]!=1) impos = true;
            if(debug)cout<<"a[i]: "<<a[i]<<endl;
        }
        if(impos) cout<<"NO";
        else{
            int i=0;
            int j=n-1;
            int dist = j-i;
            if(debug) cout<<"dist: "<<dist<<"; impos: "<<impos<<endl;
            while(dist>1 && !impos){
                if(debug) cout<<"s[i]: "<<s[i]<<"; s[i+1]: "<<s[i+1]<<"; s[j]: "<<s[j]<<"; s[j-1]: "<<s[j-1]<<endl;
                if(debug) cout<<"s[i] < s[i+1]: "<<(s[i] < s[i+1]);
                if(debug) cout<<"; s[j] < s[j-1]: "<<(s[j] < s[j-1])<<endl;
                if(debug) cout<<"; impos: "<<impos<<"; dist: "<<dist<<endl;
                if(s[i] < s[i+1] && s[i] != 'a'){
                    if(debug) cout<<"se cumple si"<<endl;
                    impos = true;
                }
                if(s[j] < s[j-1] && s[j] != 'a'){
                    if(debug) cout<<"se cumple sj"<<endl;
                    impos = true;
                }
                if(s[j] != 'a'){
                    j--;
                }
                if(s[i] != 'a'){
                    i++;
                }
                dist = j-i;
            }
            if(impos) cout<<"NO";
            else cout<<"YES";
        }
    }else{
        cout<<"NO";
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

