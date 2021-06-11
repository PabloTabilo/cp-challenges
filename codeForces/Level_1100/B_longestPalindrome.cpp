#include<iostream>
#include <unordered_map>
#include <string>
#include <map>

using namespace std;

string palindrome(string s1, int m){
    string scp = "";
    for(int i = m - 1; i >= 0; i --)
        scp += s1[i];
    return scp;
}

struct Compare{
    bool operator() (const string& s0, const string& s1) const{
        if(!s0.empty() && !s1.empty() && s0.front() == s1.front()){
            return s0 < s1;
        }else{
            return s0 < s1;
        }
    }
};

int main(){
    int n, m;
    string res="", s1, scp;
    cin>>n>>m;
    cin.ignore();
    typedef map <string, int, Compare> myMap;
    myMap mymap;
    unordered_map<string, int> umap;
    while(n--){
        // Palindromo
        // 1. Por si mismo
        // 2. Pares
        getline(cin, s1);
        //umap[s1] = 1;
        mymap[s1] = 1;
        //check palindrome
        scp = palindrome(s1, m);
        if(s1 == scp){
            //umap[s1] = 2;
            mymap[s1] = 2;
        }
    }
    int pairs = 3;
    string c1, c2;
    for(auto x : mymap){
        //cout<<x.first<<endl;
        if(x.second == 1){
            c1 = x.first;
            c2 = palindrome(c1, m);
            if(mymap[c2] == 1){
                mymap[c1] = pairs;
                mymap[c2] = pairs;
                pairs++;
                res = c1 + res + c2;
            }
        }
    }
    for(auto x : mymap){
        if(x.second == 2){
            int size = res.size();
            // first size
            string res1 = res.substr(0, size/2);;
            // second size
            string res2 = res.substr(size/2, size);
            // append
            res = res1 + x.first + res2;
            break;
        }
    }
    cout<<res.size()<<"\n";
    cout<<res<<"\n";
    return 0;
}
