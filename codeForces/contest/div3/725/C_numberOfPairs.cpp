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
        int idx_l = 0, idx_r = 0;
        int res = 0;
        bool debug = false;
        for(int i = 0; i<n;i++){
            if(debug) cout<<"A[i]: "<<A[i]<<endl;
            if(l-A[i]-1>=0){
                idx_l = bs(A, 0, i-1, l-A[i]-1);
                if(debug) cout<<"idx l (bs):"<<idx_l;
                // para no repetir pares
                // ni a si mismo
                if(idx_l>=i){
                    idx_l = -1;
                }
            }
            // no puedo buscar un valor menor a 1
            else{
                idx_l = -1;
            }
            if(debug) cout<<"; idx l (pos):"<<idx_l<<endl;
            if(r-A[i]+1>=0){
                idx_r = bs(A, 0, i-1, r-A[i]+1);
                if(debug) cout<<"idx r:"<<idx_r;
                if(idx_r>=i)
                    idx_r = -1;
            }else{
                idx_r = -1;
            }
            if(debug) cout<<"; idx r (pos):"<<idx_r<<endl;;
            
            // idx_r su index es mayor al limite i
            // El idx_l es factible?
            // Si lo es, entonces, vamos desde
            // i hasta idx_l inclusive, otro caso
            // restamos el idx_l
            if(idx_r == -1 && idx_l >=0){
                res += (A[idx_l]+A[i]>=l?i-idx_l:i-idx_l-1);
            }
            // idx_l su index es menor a 0
            // El idx_r esta dentro del rango
            // y su id es menor a i
            // id_r es factible?
            else if(idx_l == -1 && idx_r>=0){
                res += (A[idx_r]+A[i]<=r?idx_r+1:idx_r);
            }
            // si estan los rangos apuntando al mismo idx
            // Comprobar si es factible
            else if(idx_l == idx_r){
                res+= (A[i]+A[idx_l]>=l && A[i]+A[idx_r]<=r?1:0);
            // Si ambos rangos existen en el array
            }else if(idx_l >= 0 && idx_r >=0){
                // Ambos idx son inclusive
                if(A[idx_l]+A[i]>=l && A[idx_r]+A[i]<=r)
                    res += idx_r - idx_l + 1;
                // Si uno u otro es inclusive
                else if((A[idx_l]+A[i]>=l && A[idx_l]+A[i]<=r) || (A[idx_r]+A[i]<=r && A[idx_r]+A[i]>=l))
                    res += idx_r - idx_l;
                // si ninguno es inclusive
                else
                    res += idx_r - idx_l - 1;
            }
            if (debug) cout<<"; res: "<<res<<endl;
            if (debug) cout<<"-------"<<endl;
        }
        cout<<res<<endl;
    }
    return 0;
}

