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
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> A(n);
        ll sum_ai = 0;
        ll opt = 0;
        int same = 0;
        for(int i = 0; i<n;i++){
            cin>>A[i];
            sum_ai+=A[i];
            if(i>0 && A[i] == A[i-1])
                same++;
        }
        opt = sum_ai/n;
        if(n == 1 || same == n-1){
            cout<<0<<endl;
        }else{
            if(sum_ai%n!=0){
                cout<<-1<<endl;
            }else{
                int res = 0;
               for(int i = 0;i<n;i++){
                    res += (A[i]-opt>0?1:0);
               }
               cout<<res<<endl;
            }
        }
    }
    return 0;
}

