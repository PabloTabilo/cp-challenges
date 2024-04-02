
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN = 2e5;
int n;
ar<int,3> a[mxN];

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
	cin >> a[i][1] >> a[i][0] >> a[i][2];
    } 
    sort(a, a+n);
    set<ar<ll,2>> dp;
    dp.insert({0,0});
    ll ldp = 0;
    for(int i=0;i<n;i++){
	cout << " a[i] = {" << a[i][0] << "," << a[i][1] << "," << a[i][2] << endl;
	auto it = dp.lower_bound({a[i][1]});
	--it;
	cout << "dp.lower_bound = " << (*it)[0] << "," << (*it)[1] << endl;
	ldp = max(ldp, (*it)[1] + a[i][2]);
	cout<< "ldp = " << ldp << endl;
	dp.insert({a[i][0], ldp});
    }
    cout << ldp << endl;
}
