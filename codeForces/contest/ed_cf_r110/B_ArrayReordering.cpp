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
    cin>>t;
    while(t--){
        int n, a;
        cin>>n;
        vector<int> A(n);
        vector<int> odd, even;
        int count1 = 0, count2 = 0;
        for(int i = 0;i<n;i++){
            cin>>a;
            if(a >= 2 && a%2==0)
                even.push_back(a);
            else
                odd.push_back(a);
        }
        sort(even.begin(), even.end(), greater<int>());
        sort(odd.begin(), odd.end(), greater<int>());
        int i=0;
        while(i < n){
            if(i < even.size())
                A[i] = even[i];
            else
                A[i] = odd[i-even.size()];
            //cout<<"i: "<<i<<"; A[i]"<<A[i]<<endl;
            i++;
        }
        int res = 0;
        for(int i = 0;i<n;i++){
            for(int j = i+1; j< n; j++){
                if(gcd(A[i], 2*A[j])>1)
                    res++;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}

