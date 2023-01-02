#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    int n, num;
    cin>>n;
    int contador = 0;
    int totalSum = 0;
    unordered_map<int, int> umap;
    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        if(num != 4){
            totalSum += num;
            umap[num]++;
        }else
            contador++;
    }

    for(unordered_map<int,int>:: iterator it = umap.begin(); it != umap.end(); it++){
        int comp = 4 - it->first;
        while(it->second > 0 && umap[comp] > 0){
            if(it->first % 2 == 0){
                if(umap[2] - 2 >= 0){
                    umap[2]-=2;
                    contador++;
                }else
                    break;
            }else{
                umap[comp]--;
                umap[it->first]--;
                contador++;
            }
        }
    }
    
    
    /*
    cout<<contador<<endl;
    cout<<endl;
    cout<<umap[3]<<endl;
    cout<<umap[2]<<endl;
    cout<<umap[1]<<endl;
    cout<<endl;
    */

    // De aqui en adelante puedo tener:
    // 1s solos o 3 solos o un 2 solo
    // 1s y un 2 solo
    // 3s y un 2 solo

    if(umap[2] > 0 && umap[1] > 0){
        if(umap[1] < 3){
            contador += 1;
        }else{
            umap[1] = umap[1] - 2;
            contador += 1;
            if(umap[1] <= 4){
                contador += 1;
            }else{
                if(umap[1]%4 == 0)
                    contador += umap[1]/4;
                else
                    contador += umap[1]/4 + 1;
            }
        }
        umap[1] = 0;
        umap[2] = 0;
    }else if(umap[3] > 0 && umap[2] > 0){
        contador += umap[3] + umap[2];
        umap[3] = 0;
        umap[2] = 0;
    }else if(umap[1] > 0){
        if(umap[1] <= 4){
            contador += 1;
        }else{
            if(umap[1]%4==0){
                contador += umap[1]/4;
            }else{
                contador += umap[1]/4 + 1;
            }
        }
        umap[1] = 0;
    }else if(umap[2] > 0){
        contador += umap[2];
    }else if(umap[3] > 0){
        contador += umap[3];
    }
    

    cout<<contador<<endl;
    return 0;
}
