#include<bits/stdc++.h>

using namespace std;

void dfs(int node, int parent, int dist, unordered_map<int,vector<int>> g, unordered_map<int,bool> & vis, unordered_map<int, map<int, vector<int>> > & d){
    if(dist > 0){
	d[node][dist].push_back(parent);
    } 
    vis[parent] = true;
    for(int n : g[parent]){
	if(vis.find(n) == vis.end()){
	    dfs(node, n, dist+1, g, vis, d);
	}
    }
}

void solve(){
    int n;
    int u, v;
    cin >> n;
    unordered_map<int,vector<int>> g;
    for(int i=0;i<n-1;i++){
	cin >> u >> v;
	g[u].push_back(v);
	g[v].push_back(u);
    }
    unordered_map<int, map<int, vector<int>> > d;
    unordered_map<int,bool> vis;
    for(pair<int, vector<int>> p : g){
	dfs(p.first, p.first, 0, g, vis, d);
	vis.clear();
    }

    for(auto p : d){
	cout << "p.first = " << p.first << endl;
	for(auto dd : d[p.first]){
	    cout << "dist = " << dd.first << endl;
	    for(auto x : dd.second) cout << x << ", ";
	    cout << endl;
	}
	cout << "----------------------------" << endl;
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
