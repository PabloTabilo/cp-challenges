#include<iostream>
#include<string>

using namespace std;

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s1=to_string(n);
        int res = (s1.size()-1)*9;
        if(s1.size()==1)
            cout<<n<<endl;
        else{
            int firstDigit=s1[0]-'0';
            string numberFD = "";
            for(int i=0;i<s1.size();i++){
                numberFD+=s1[0];
            }
            int rep = stoi(numberFD);
            //cout<<rep<<endl;
            //cout<<n<<endl;
            if(rep<=n){
                res+=firstDigit;
            }else{
                res+=firstDigit-1;
            }
            cout<<res<<endl;
        }
    }
    return 0;
}
