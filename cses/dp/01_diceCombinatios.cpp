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

#define MEM(a, b) memset(a, (b), sizeof(a))
#define _USE_MATH_DEFINES
#define PI 3.1415926535897932384626433832795

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int ll;
typedef unsigned long long int uint64;
typedef long double ld80;

using namespace std;

int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

void pV(vector<int> V, int n){
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<V[i]<<" ";
    cout<<endl;
}

void pAr(int A[], int n){
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
}
// https://cses.fi/problemset/task/1633
ll mod = 1e9 + 7;
int main(){
    // read & write file
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    // fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n;
    cin>>n;
    ll dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i<=n; i++)
        dp[i] = dp[i-1]%mod + dp[i-2]%mod + (i-3>=0?dp[i-3]%mod:0) + (i-4>=0?dp[i-4]%mod:0) + (i-5>=0?dp[i-5]%mod:0) + (i-6>=0?dp[i-6]%mod:0);
    cout<<dp[n]%mod<<endl;
    return 0;
}

