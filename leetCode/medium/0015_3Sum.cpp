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
    public:
        vector<vector<int>> threeSum(vector<int> &nums){
            vector<vector<int>> res;
            int n = nums.size();
           debug(nums);
           sort(nums.begin(), nums.begin() + n);
           debug(nums);
           for(int i = 0; i < n; i++){
               if(i > 0 && nums[i] == nums[i-1]) continue;
                    int l = i + 1;
                    int h = nums.size() - 1;
                    int sum = 0 - nums[i];
                    vector<int> t(3);
                    while(l < h){
                        if(nums[l] + nums[h] == sum){
                            t[0] = nums[i];
                            t[1] = nums[l];
                            t[2] = nums[h];
                            res.push_back(t);
                            while(l < h && nums[l] == nums[l+1]) l++;
                            while(l < h && nums[h] == nums[h-1]) h--;
                            l++;
                            h--;
                        }else if(nums[l] + nums[h] > sum){
                            h--;
                        }else{
                            l++;
                        }
                    }
           }
           return res;
        }
};

void solve(){
   Solution sol = Solution();
   vector<int> example = {-1, 0, 1, 2, -1, -4};
   vector<vector<int>> res = sol.threeSum(example);
   for(int i=0; i < res.size();i++){
       cout<<"Vector on position: "<<i<<endl;
        for(int j = 0; j<res[i].size();j++){
            cout<<res[i][j];
        }
        cout<<endl;
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

