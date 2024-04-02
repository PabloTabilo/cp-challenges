
#include<bits/stdc++.h>

using namespace std;

const int mxN = 1e3;
int n, m;
string g[mxN];

bool poss(int i, int j){
    return i>=0 && i < n && j >= 0 && j < m && g[i][j] == '.';
}


void dfs(int i, int j){
    g[i][j] = '#';
    if(poss(i-1, j)){
	dfs(i-1, j);
    }
    
    if(poss(i, j-1)){
	dfs(i, j-1);
    }

    if(poss(i + 1, j)){
	dfs(i + 1, j);
    }

    if(poss(i, j + 1)){
	dfs(i, j + 1);
    }
}


int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
	cin >> g[i];
    }
    
    int cl = 0;
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    if(poss(i, j)){
		dfs(i, j);
		cl++;
	    }
	}
    }
    cout<<cl<<endl;
}
