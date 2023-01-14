#include<iostream>
#include<queue>

using namespace std;

void printArr(int **p, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int **p = new int*[n];
        for(int i=0;i<n;i++)
            p[i] = new int[n];
        queue<int> e;
        queue<int> o;
        o.push(1);
        for(int i=2;i<=n*n;i++){
            if(i%2==0)
                e.push(i);
            else
                o.push(i);
        }
        printArr(p, n);
        int i = 0, j;
        while(!e.empty()){
            j=0;
            while(j<n && !e.empty()){
                //cout<<"i: "<<i<<" j:"<<j;
                p[i][j] = e.front();
                //cout<<" p[i][j]: "<<p[i][j]<<endl;
                e.pop();
                j++;
            }
            if(j==n)
                i++;
        }
        //cout<<"odd"<<endl;
        //cout<<i<<" - "<<j<<endl;
        
        while(!o.empty()){
            while(j<n && !o.empty()){
                p[i][j] = o.front();
                o.pop();
                j++;
            }
            j=0;
            i++;
        }
        printArr(p, n);
    }
    return 0;
}
