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
    int n;
    cin>>n;
    cin.ignore();
    vector<string> v1;
    for(int i =0; i<n; i++){
        cin>>v1[i];
    }
    // check possibles
    
    // check orders
    int dis = 0;
    for(int i = 0; i<n;i++){
        for(int j = i+1; j<n;j++){
            set<char> pos;
            int sSize = v1[i].size();
            for(int k = 0; k<sSize; k++){
                pos.insert(v1[i][k]);
                pos.insert(v1[j][k]);
                if(v1[i][k] != v1[j][k]){
                    dis++;
                }
            }
            if(pos.size() != n){
                res+= 1337;
            }else{
                
            }
        }
    }
    return 0;
}

