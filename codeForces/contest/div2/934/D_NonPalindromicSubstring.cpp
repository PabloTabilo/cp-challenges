#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> dp(n, vector<int>(n,0));
    string s;
    cin >> s;
    //cout << "string s = " << s << endl;
    for(int k = 1; k < n; k++){
	for(int i = 0; i+k < n; i++){
	    int j = i+k;
	    if(s[i] != s[j]){
		dp[i][j] = k+1;
	    } 
	    else if(dp[i+1][j-1] > 0){
		dp[i][j] = dp[i+1][j-1] + 2;
	    }
	    if(dp[i][j] == 0){
		dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
	    }
	    // 0,1
	    // 1,2
	    // 2,3
	    //
	    // 0,2
	    // 1,3
	    //
	    // 0,3
	}

    }
    //cout << "dp : " << endl; for(auto r : dp){for(auto c : r) cout << c << " "; cout << endl;}

    while(q--){
	int l, r;
	cin >> l >> r;
	l--;
	r--;
	int a = dp[l][r];
	cout << max(((a*(a+1)) / 2) - 1, 0) << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
	solve();
    }
    return 0;
}
