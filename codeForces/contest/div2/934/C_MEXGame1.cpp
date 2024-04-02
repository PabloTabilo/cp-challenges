#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
	int n;
	cin >> n;
	int f[n + 1];
	memset(f, 0, sizeof(f));
	for(int i=0;i<n;i++){
	    int x; cin >> x;
	    f[x]++;
	}
	int ans = 0;
	for(int i = 0; i <= n; i++){
	    ans += (f[i] == 1);
	    if(ans == 2 || f[i] == 0){
		cout << i << endl;
		break;
	    }

	}
    }
    return 0;
}
