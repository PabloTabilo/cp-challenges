#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> m(n); 
    int sume=0;
    for(int i=0;i<n;i++) {
	cin>>m[i];
	sume+=m[i];
    }
    vector<int> dp(sume+1,0);

    sort(m.begin(),m.end());
    dp[0]=1;
    int s=0;
    for(int k=0;k<n;k++){
	for(int i=sume; i>=0;i--){
	    if(i-m[k]>=0){
		dp[i]+=dp[i-m[k]];
	    }	
	}
    }
    for(int x=1;x<sume+1;x++) if(dp[x]!=0) s++;
    cout<<s<<endl;
    for(int x=1;x<sume+1;x++) if(dp[x]!=0) cout<<x<<" ";
    cout<<endl;
    return 0;
}

