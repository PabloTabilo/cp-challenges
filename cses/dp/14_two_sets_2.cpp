
#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int mxN = 5e2;
int n;
int MOD = 1e9 + 7;

ll dp[mxN * (mxN + 1) / 2 + 1];

int main(){
    cin>>n;
    int s = (n * (n+1)) >> 1;
    if(s&1){
	cout<<0<<endl;
	return 0;
    }
    s/=2;
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
	for(int j = i*(i+1)/2; j>=i; j--){
	    dp[j] = (dp[j] + dp[j - i]) % MOD;
	}
	cout << "i = " << i << ", dp : "; for(int k = 0; k <= s; k++) cout << dp[k] << " "; cout<<endl;
    }

}
