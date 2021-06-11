#include <iostream>

using namespace std;

int main(){
    int r, g, b;
    cin>>r>>g>>b;
    int r_cc = r/2;
    int g_cc = g/2;
    int b_cc = b/2;

    if(r%2!=0)
        r_cc++;
    if(g%2!=0)
        g_cc++;
    if(b%2!=0)
        b_cc++;
    int res = 29;
    while(r_cc > 0 | g_cc > 0 | b_cc > 0){
       //cout<<r_cc<<" "<<g_cc<<" "<<b_cc<<endl;
        if(r_cc+g_cc+b_cc==1)
            res+=r_cc+2*g_cc+3*b_cc;
        else if(r_cc+g_cc+b_cc==2 && r_cc != 2 && g_cc!=2 && b_cc!=2)
            if(b_cc == 1)
                res+=3;
            else
                res+=2;
        else
            res+=3;
        if(r_cc>0)
            r_cc--;
        if(g_cc>0)
            g_cc--;
        if(b_cc>0)
            b_cc--;
    }
    cout<<res<<'\n';

    return 0;
}
