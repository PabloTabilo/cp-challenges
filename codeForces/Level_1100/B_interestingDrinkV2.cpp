#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n, q, x;
    cin>>n;
    vector<int>a(n);
    for(int i = 0; i < n; i++)
        cin>>a[i];
    sort(a.begin(), a.end());
    cin>>q;
    while(q--){
        cin>>x;
        auto ans = upper_bound(a.begin(), a.end(), x);
        if(x<a[0]){
            cout<<0<<'\n';
            continue;
        }
        if(x>=a[n-1]){
            cout<<n<<'\n';
            continue;
        }
        // input: 10 20 30 30 40 50
        // upper_bound for element 30 is at index 4
        cout<<ans-a.begin()<<'\n'; 
    }
    
    return 0;
}
