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

int bs(vector<int> A, int l, int r, int k){
    if(l<r){
      int m = (l+r)/2;
      if(A[m] == k)
          return m;
      else if(A[m] > k)
          return bs(A, l, m-1, k);
      else
          return bs(A, m+1, r, k);
    }
    return l;
}

int main(){
    // read & write file
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    // fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t, n;
    ll l, r;
    cin>>t;
    while(t--){
        cin>>n>>l>>r;
        vector<int>A(n);
        for(int i = 0; i<n;i++){
            cin>>A[i];
        }
        sort(A.begin(), A.end());
        int resl = 0, resr = 0;
        int res = 0;
        bool debug = true;
        for(int i = 0; i<n;i++){
            if(debug) cout<<"A[i]: "<<A[i]<<endl;
            if(l-A[i]>0){
                resl = bs(A, 0, i-1, l-A[i]);
                if(debug) cout<<"idx l:"<<resl;
                // para no repetir pares
                // ni a si mismo
                if(resl>=i)
                    resl = -1;
            }
            // no puedo buscar un valor menor a 1
            else{
                resl = -1;
            }
            if(r-A[i]>0){
                resr = bs(A, 0, i-1, r-A[i]);
                if(debug) cout<<"; idx r:"<<resr<<endl;
                if(resr>=i)
                    resr = -1;
            }else{
                resr = -1;
            }
            if (debug) cout<<"resr: "<<resr<<"; resl: "<<resl<<endl;
            if(resr == -1 && resl >=0)
                res += i - resl;
            else if(resl == -1 && resr>=0)
                res += resr + 1;
            else if(resl == resr){
                res+= (A[i]+A[resl]>=l && A[i]+A[resr]<=r?1:0);
            }else if(resl >= 0 && resr >=0)
                res += resr - resl + 1;
        }
        cout<<res<<endl;
    }
    return 0;
}

