#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	int n;
	cin >> n;
	vector<int> a(n);
	int max_val = 0;
	int sume = 0;
	for(int i=0;i<n;i++){
	    cin >> a[i];
	    max_val = max(max_val, a[i]);
	    sume += a[i];
	}
	int mid = (n / 2) + 1;
	int l = 0;
	int r = 1e6 + 1;
	int ans = INT_MAX;
	while(l <= r){
	    int x = (l + r) >> 1;
	    double av = (double)(sume + x + .0) / (n+.0);
	    int unhappy = 0;
	    bool eliminate_max = false;
	    for(int i=0;i<n;i++){
		if(a[i] == max_val && !eliminate_max){
		    eliminate_max = true;
		    continue;
		}
		if((double)a[i] < av){
		    unhappy++;
		}
	    }
	    if(unhappy >= mid){
		ans = min(ans, x);
		r = x - 1;
	    }else if(unhappy < mid){
		l = x + 1;
	    }
	}
	if(ans == INT_MAX) ans = -1;
	cout << "ans = ";
	cout << ans << endl;
    }

    return 0;
}

