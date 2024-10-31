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
	cin >> n >> k;
	int start = n - k + 1;

	int remainder = k % 4;
	if(remainder == 1){
	    if( (start % 2 == 0) && (n % 2 == 0)){
		cout << "YES";
	    }else{
		cout << "NO";
	    }
	}
	else if(remainder == 2){
	    cout << "NO";
	}
	else if(remainder == 3){
	    if( (start % 2 != 0) && (n % 2 != 0)){
		cout << "YES";
	    }else{
		cout << "NO";
	    }
	}else{
	    cout << "YES";	    
	}
	cout << endl;
    }

    return 0;
}

