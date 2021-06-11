#include<iostream>
#include<vector>
using namespace std;

int findMax(vector<int>A, vector<int>B){
    int nA = A.size();
    int nB = B.size();
    int maxV=0;
    int acA=0;
    for(int i=0;i<nA;i++){
        acA+=A[i];
        maxV=max(maxV, A[i]);
    }
    
    int acB=0;
    for(int i=0;i<nB;i++){
        acB+=B[i];
        maxV=max(maxV, B[i]);
    }

    maxV+=1;
    int H[maxV];
    for(int i=0;i<maxV;i++)
        H[i]=0;
    
    for(int i=0;i<nA;i++)
        H[A[i]]++;
    
    for(int i=0;i<nB;i++)
        H[B[i]]+=2;
    
    int bestAcum=0;
    bool notFilter=false;
    int filter=-1;
    for(int i=maxV-1;i>=0;i--){
        if(H[i]>0 && !notFilter){
            bestAcum+=i;
            if(H[i]==1){
                acA-=bestAcum;
            }else if(H[i]==2){
                acB-=bestAcum;
            }else if(H[i]==3){
                acA-=bestAcum;
                acB-=bestAcum;
                if(acA > acB){
                    notFilter=true;
                    filter=1;
                }else{
                    notFilter=true;
                    filter=2;
                }
            }
            if(H[i]==filter){
                
            }
        }
    }

    return 0;
}

int main(){
    vector<int> A = { 1,3,5,8,10,12,14 };
    vector<int> B = { 2,5,6,7,8,11,13,14,16,17 };
    int res = findMax(A, B);
    // suma de {1,3,5,6,7,8,11,13,14,16,17}
    cout<<res<<endl;
    return 0;
}
