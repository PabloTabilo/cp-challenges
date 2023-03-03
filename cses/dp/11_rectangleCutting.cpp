#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(501,vector<int>(501,INT_MAX));

void fill_dp(){
    for(int i=1;i<501;i++){
	for(int j=1;j<501;j++){
	    if(i!=j){
		for(int w=1;w<i;w++){
		    dp[i][j] = min(dp[i][j],dp[w][j]+dp[i-w][j]+1);
		}
		for(int h=1;h<j;h++){
		    dp[i][j] = min(dp[i][j],dp[i][h]+dp[i][j-h]+1);
		}
	    }else{
		dp[i][j]=0;
	    }	
	}
    }
}

int main(){
    fill_dp();
    int a, b;
    cin>>a>>b;
    cout<<dp[a][b]<<endl;
    return 0;
}
