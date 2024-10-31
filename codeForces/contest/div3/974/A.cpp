#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	int n, k;
	int take_gold = 0;
	int ans = 0;
	cin >> n >> k;
	int ai = 0;
	for(int i=0;i<n;i++){
	    cin >> ai;
	    if(ai >= k){
		take_gold += ai;	
	    }else if(ai == 0 && take_gold > 0){
		take_gold--;
		ans++;
	    }
	}
	//cout << "ans = ";
	cout << ans << endl;
    }
    return 0;
}

