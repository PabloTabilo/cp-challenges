#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<iterator>
#include<stack>
#include<set>
#include<unordered_map>
#include<map>
#include<math.h>
#include<limits>
#include<iomanip>
#include<sstream>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define _USE_MATH_DEFINES
#define PI 3.1415926535897932384626433832795

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int ll;
typedef unsigned long long int uint64;
typedef long double ld80;

using namespace std;

int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

void pV(vector<int> V, int n){
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<V[i]<<" ";
    cout<<endl;
}

void pAr(int A[], int n){
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

int main(){
    // read & write file
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    // fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t;
    int s1, s2, s3, s4;
    cin>>t;
    while(t--){
        cin>>s1>>s2>>s3>>s4;
        int fM = max(s1, s2);
        int sM = max(s3, s4);
        int mx = max(fM, sM);
        if(s1 == mx)
            s1 = -2;
        if(s2 == mx)
            s2 = -2;
        if(s3 == mx)
            s3 = -2;
        if(s4 == mx)
            s4 = -2;
        int smx = max(s1, max(s2, max(s3, s4)));
        if((smx == fM || smx == sM) && (mx == fM || mx == sM))
            cout<<"YES";
        else
            cout<<"NO";
        cout<<endl;

    }
    return 0;
}

