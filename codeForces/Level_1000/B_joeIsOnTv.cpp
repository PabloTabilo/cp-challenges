#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int n;
    cin>>n;
    long double ans = 0.;
    for(int i = 1; i <= n; i++){
        ans += 1./(i+.0);
    }
    //cout<<setprecision(13);
    //cout<<fixed;
    //cout<<ans<<endl;
    printf("%14Lf", ans);
    return 0;
}
