#include<iostream>
#include<unordered_map>
#include<climits>
#include<vector>
using namespace std;
 
int n, W;
unordered_map<int, int> dp;
 
int solve(vector<int> weights, int current_sum, int mask, int current_rides){
 
    if(mask == ((1<<n)-1)){
	return current_rides + 1;
    }
 
    if(dp.find(mask) != dp.end()) return dp[mask];
    
    int min_rides = INT_MAX;
    for(int i=0;i<n;i++){
	if(mask & (1 << i)) continue;
	if(current_sum + weights[i] <= W){
	    min_rides = min(min_rides, solve(weights, current_sum + weights[i], mask | (1<<i), current_rides));
	}
    }
    
    // not exits a valid neight
    if(current_sum > 0) min_rides = min(min_rides, solve(weights, 0, mask, current_rides + 1));
    
    dp[mask] = min_rides;
    return min_rides;
}
 
string bin_r(int x){
    if(x == 0){
	return "0";
    }
    int highest_bit = 31 - __builtin_clz(x);
    string binary;
    for(int i = highest_bit; i >= 0; i--){
	if(x & (1 << i)) binary += "1";
	else binary += "0";
    }
    return binary;
}
 
int main(){
    cin >> n >> W;
    vector<int> weights(n);
    for(int i=0;i<n;i++) cin >> weights[i];
    int ans = solve(weights, 0, 0, 0);
    cout << ans << endl;
    //for(pair<int, int> p : dp){cout << bin_r(p.first) << " = " << p.second << endl;} 
    return 0;
}
