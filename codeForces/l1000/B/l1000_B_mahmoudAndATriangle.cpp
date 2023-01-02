#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, num;
    cin>>n;
    vector<int> v1(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        v1[i] = num;
    }
    sort(v1.begin(), v1.end(), greater<int>());
    int a, b, c;
    bool check = false;
    for(int i = 0; i < n; i++){
        if(i+2 < n){
            a = v1[i];
            b = v1[i+1];
            c = v1[i+2];
            if(a+b>c && a+c>b && b+c>a){
                check = true;
                cout<<"YES"<<endl;
                break;
            }
        }
    }
    if(!check)
        cout<<"NO"<<endl;

    return 0;
}
