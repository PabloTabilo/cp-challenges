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


class Solution{
    unordered_map<string, string> M = {
        {"1", "M"},
        {"2", "M"},
        {"3", "M"}
    };

    unordered_map<string, string> C = {
        {"1", "C"},
        {"2", "CC"},
        {"3", "CCC"},
        {"4", "CD"},
        {"5", "D"},
        {"6", "DC"},
        {"7", "DCC"},
        {"8", "DCCC"},
        {"9", "CM"}
    };
    
    unordered_map<string, string> D = {
        {"1", "X"},
        {"2", "XX"},
        {"3", "XXX"},
        {"4", "XL"},
        {"5", "L"},
        {"6", "LX"},
        {"7", "LXX"},
        {"8", "LXXX"},
        {"9", "XC"}
    };

    unordered_map<string, string> U = {
        {"1", "I"},
        {"2", "II"},
        {"3", "III"},
        {"4", "IV"},
        {"5", "V"},
        {"6", "VI"},
        {"7", "VII"},
        {"8", "VIII"},
        {"9", "IX"}
    };

    public:
        string intToRoman(int num){
            stringstream ss;
            ss<<num;
            string s, res = "";
            ss>>s;
            int digits = (int)floor(log10(num) + 1);
            int i = 0;
            string temp = "";
            while(digits > 0){
                temp += s[i];
                if(digits == 1){
                    res += U[temp];
                }else if(digits == 2){
                    res += D[temp];
                }else if(digits == 3){
                    res += C[temp];
                }else if(digits == 4){
                    res += M[temp];
                }
                digits--;
                i++;
                temp = "";
            }
            return res;
        }
};

void solve(){
    int n;
    cout<<"Dame un num: ";
    cin>>n;
    Solution sol = Solution();
    string res = sol.intToRoman(n);
    cout<<"res: "<<res<<endl;
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
    cout<<"Num de veces para repetir: ";
    cin>>t;
    cout<<endl;
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

