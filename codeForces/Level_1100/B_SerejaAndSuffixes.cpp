#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

bool check[100001];
int n, m, i, l, a[100000], ans[100001];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(i = n-1; i >= 0; i--){
        if(!check[a[i]]){
            check[a[i]] = 1;
            ans[i] = ans[i+1] + 1;
        }else{
            ans[i] = ans[i+1];
        }

        //cout<<"i: "<<i<<endl;
        //cout<<"a[i]: "<<a[i]<<endl;
        //cout<<"check[a[i]]: "<<check[a[i]]<<endl;
        //cout<<"ans[i]: "<<ans[i]<<endl;
    }
    
    while(m--){
        scanf("%d", &l);
        printf("%d\n", ans[l-1]);
    }
    return 0;
}
