#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int MOD = 1e9 + 7;
int n;

int main(){
    cin >> n;
    ll dp[n * (n+1) / 2 + 1] = {0};
    dp[0] = 1;

    for(int i=1; i <= n; i++){
	int s = i*(i+1) / 2;
	if(s%2 == 0){
	    s /= 2;
	    for(int j = s; j >= i; j--){
		dp[j] = (dp[j] + dp[j - i]) % MOD;
	    }
	}
	cout<<"i = " << i << ", dp: "; for(int k = 0; k <= n*(n+1)/2; k++) cout<<dp[k]<<" "; cout<<endl;
    }

    cout << dp[n * (n+1) / 2 + 1] << endl;

}
