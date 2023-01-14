#include<iostream>
#include<string>
#include<unordered_map>
#include<stack>

using namespace std;

int main(){
    int t, n;
    cin>>t;
    cin.ignore();
    while(t--){
        cin>>n;
        cin.ignore();
        string s1;
        stack<char> stk;
        char letter;
        unordered_map<char, bool> umap;
        bool notDis=false;
        for(int i =0;i<n;i++){
            cin>>letter;
            if(stk.empty()){
                stk.push(letter);
                s1+=letter;
                umap[letter]=true;
            }else{
                if(stk.top() != letter){
                    stk.push(letter);
                    s1+=letter;
                    umap[letter]=true;
                }
            }
        }
        //cout<<s1<<endl;    
        for(int i =0;i<s1.size();i++){
            if(umap[s1[i]])
                umap[s1[i]]=false;
            else{
                notDis=true;
                break;
            }
        }
        if(notDis)
            cout<<"NO";
        else
            cout<<"YES";
        cout<<endl;
    }
    return 0;
}
