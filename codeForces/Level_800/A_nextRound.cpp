#include <iostream>

using namespace std;

int main(){
    int n, k, num;
    int contador = 0, position = 1;
    int score_k = 0;
    cin>>n>>k;
    cin.ignore();
    while(n--){
        cin>>num;
        if(position < k){
            contador += (num>0? 1 : 0);
        }
        if(position == k){
            score_k = num;
        }
        if(position >= k){
            //cout<<"num : "<<num<<endl;
            //cout<<"score_k : "<<score_k<<endl;
            contador += (num>0 && num==score_k? 1 : 0);
        }
        position += 1;
    }
    cout<<contador<<'\n';
    return 0;
}
