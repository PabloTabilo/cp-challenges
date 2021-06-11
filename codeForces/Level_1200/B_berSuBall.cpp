#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n, m;
    cin>>n;
    cin.ignore();
    int val;
    int a[n];
    bool a_b[101] = {false};
    int a_f[101] = {0};
    for(int i = 0; i < n; i++){
        cin>>val;
        a[i] = val;
        a_f[val]++;
    }
    cin>>m;
    cin.ignore();

    int b[m];
    bool b_b[101] = {false};
    int b_f[101] = {0};
    for(int i = 0; i < m; i++){
        cin>>val;
        b[i] = val;
        b_f[val]++;
    }
    
    vector<int> av;
    vector<int> bv;

    for(int i = 0; i < 100; i++){
        if(a_f[i] > 0 && !a_b[i]){
            for(int j = 0; j < 100; j++){
                if(b_f[j] > 0 && !b_b[j]){
                    int dist = i - j;
                    if(dist == 1 || dist == -1){
                        a_b[i] = true;
                        b_b[j] = true;
                        av.push_back(i);
                        bv.push_back(j);
                    }
                    if(dist < -1){
                        break;
                    }
                }
            }
        }
    }
    cout<<endl;
    for(auto x: av){
        cout<<x<<" ";
    }
    cout<<endl;
    for(auto x: bv){
        cout<<x<<" ";
    }

    cout<<'\n';

    return 0;
}
