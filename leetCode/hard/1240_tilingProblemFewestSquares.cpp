#include<iostream>

using namespace std;

void printArr(int A[14][14]){
    cout<<endl;
    for(int i=0;i<14;i++){
        for(int j=0;j<14;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void initArr(int A[14][14]){
    for(int i=0;i<14;i++)
        for(int j=0;j<14;j++)
            A[i][j]=0;
}

int tilingRectangle(int n, int m) {
        int dp[14][14];
        initArr(dp);
        for(int i=0;i<14;i++){
            dp[i][i]=1;
            dp[0][i]=0;
            dp[i][0]=0;
            dp[1][i]=i;
        }
        printArr(dp);
        int res;
        for(int i=2;i<14;i++){
            for(int j=i+1;j<14;j++){
                res=999999;
                for(int k=min(i,j);k>=1;k--){
                    // escogo un k,k
                    // tendre un i-k,k
                    // y un i,j-k
                    // o puede leerlo tambienn
                    // j-k,k
                    // i-k,k
                    // Si tengo un i,j = 3,5
                    // Y selecciono un k =2, es decir, 2,2
                    // entonces 
                    // A: 2,2 + 1,2 + 3,3
                    // B: 2,2 + 1,5 + 2,3
                    res = min(res, dp[k][k] + dp[min(i-k,k)][max(i-k,k)] + dp[min(k,j-k)][max(j-k,i)]);
                    res = min(res, dp[k][k] + dp[min(i-k,j)][max(i-k,j)] + dp[min(k,j-k)][max(j-k,k)]);
                }
                dp[i][j] = res;
            }
        }
        printArr(dp);
        
        return dp[n][m];
    }

int main(){
    int n, m;
    cin>>n>>m;
    int res = tilingRectangle(n,m);
    cout<<res<<endl;
    return 0;
}
