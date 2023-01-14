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
        vector<int>A(n);
        int minV = 999;
        int id_min=0;
        int maxV = -1;
        int id_max=0;
        int res = 0;
        for(int i = 0; i<n;i++){
            cin>>A[i];
            if(A[i]>maxV){
                maxV = A[i];
                id_max = i;
            }
            if(A[i]<minV){
                minV = A[i];
                id_min = i;
            }
        }
        //cout<<"id_max: "<<id_max<<"; id_min: "<<id_min<<endl;
        int i = 0, j = n-1;
        int ci = 1;
        int cj = 1;
        if(id_min < id_max){
            res = id_max - id_min + 1;
            res += min(id_min-i, j-id_max);
            while(i < id_min){i++; ci++;}
            while(j > id_max){j--; cj++;}
        }else{
            res = id_min - id_max + 1;
            res += min(id_max-i, j-id_min);
            while(j > id_min){j--; cj++;}
            while(i < id_max){i++; ci++;}
        }
        res = min(res, ci+cj);
        cout<<res<<endl;
    }
    return 0;
}

