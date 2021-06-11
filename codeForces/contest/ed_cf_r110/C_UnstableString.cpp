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
    string s;
    cin>>t;
    cin.ignore();
    while(t--){
        getline(cin, s);
        int n = s.size();
        int i = 2, j;
        int res = 0;
        while(i <= n){
            j = 0;
            stack<int> check;
            while(j<n){
                if(check.empty())
                    check.push(s[j]);
                else{
                    if(check.top() == "0" && s[j]=="0"){
                        
                    }else if(check.top() == "1" && s[j]=="1"){

                    }else{
                        check.push(s[j]);
                    }
                }
                if(check.size() == i){
                    res++;
                }
                j++;
            }
            i++;
        }
    }
    return 0;
}

