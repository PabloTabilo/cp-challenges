#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        double res = 2.0 / (1.0 - (a/180.0));
        res /= 1.0;
        //cout<<" ----------- "<<endl;
        //cout<<"res: "<<res<<endl;
        //cout<<"fmod(res, 1.0): "<<fmod(res, 1.0)<<endl;
        //cout<<"floor: "<<floor(res)<<endl;
        //cout<<"ceil: "<<ceil(res)<<endl;
        //cout<<"res / 1.0: " << res / 1.0<<endl;
        //cout<<"res - int(res)" << abs(res - ceil(res))<<endl;
        
        //cout<<"(int)res: "<<(int)res<<endl;
        if(abs(res - ceil(res)) < pow(10,-14)){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        cout<<"\n";
    }
    return 0;
}
