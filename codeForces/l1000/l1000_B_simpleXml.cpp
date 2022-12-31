#include <iostream>
#include <iomanip>
#include <stack>
#include <unordered_map>
#include <queue>

// mytest: <a><b></b><d><c></c><e></e><f><g></g><h></h></f></d></a>

using namespace std;

int main(){
    string xml;
    getline(cin, xml);
    int n = xml.size();
    // Pueden ser dos pilas
    // nombre del nodo
    // profunidad del tree
    unordered_map<int, int> umap;
    stack<char> sChange;
    //queue<char> sUnique;
    //queue<int> deepUnique;
    int code;
    char sameChar, prevCharClose;
    for(int i = 0; i < n; i++){
        code = xml[i];
        prevCharClose = xml[i-1];
        if(code > 96 && code < 123){
            if(!sChange.empty()){
                sameChar = sChange.top();
                if(sameChar == xml[i] && prevCharClose == '/'){
                    umap[i] = sChange.size()-1;
                    sChange.pop();
                }else{
                    sChange.push(xml[i]);
                    //sUnique.push(xml[i]);
                    //deepUnique.push(sChange.size()-1);
                    umap[i] = sChange.size()-1;
                }
            }else{
                sChange.push(xml[i]);
                //deepUnique.push(0);
                //sUnique.push(xml[i]);
                umap[i] = 0;
                }
            
        }
    }

    //cout<<endl<<endl<<endl;
    
    stack<int> lastChar;
    char temporal = '\0';
    char valCurrent;
    int mydeep;
    for(int i = 0; i < n; i++){
        code = xml[i];
        if(code > 96 && code < 123){
            valCurrent = xml[i];
            mydeep = umap[i];
            prevCharClose = xml[i-1];
            //cout<<"ValCurrent: "<<valCurrent<<endl;
            //cout<<"mydeep : "<<mydeep<<endl;
            //cout<<"prevCharClose: "<<prevCharClose<<endl;

            if(lastChar.empty()){
                lastChar.push(valCurrent);
                if(temporal != '\0')
                    cout<<endl;
                cout<<"<"<<valCurrent<<">"; 
            }else{
                //cout<<lastChar.top()<<endl;
                sameChar = lastChar.top();
                if(sameChar == valCurrent && prevCharClose == '/'){
                    lastChar.pop();
                    cout<<endl;
                    for(int j = 0; j < mydeep*2; j++)
                        cout<<" ";
                    cout<<"</"<<valCurrent<<">";
                }else{
                    lastChar.push(valCurrent);
                    cout<<endl;
                    for(int j = 0; j < mydeep*2; j++)
                        cout<<" ";
                    cout<<"<"<<valCurrent<<">";
                }
            }
            temporal = valCurrent;
        }
    }

    return 0;
}
