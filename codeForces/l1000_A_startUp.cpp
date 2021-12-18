#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    string word;
    getline(cin, word);
    int n = word.size();
    int mid = n/2;
    unordered_map<char, bool> um;
    um['A'] = true;
    um['B'] = false;
    um['C'] = false;
    um['D'] = false;
    um['E'] = false;
    um['F'] = false;
    um['G'] = false;
    um['H'] = true;
    um['I'] = true;
    um['J'] = false;
    um['K'] = false;
    um['L'] = false;
    um['M'] = true;
    um['N'] = false;
    um['O'] = true;
    um['P'] = false;
    um['Q'] = false;
    um['R'] = false;
    um['S'] = false;
    um['T'] = true;
    um['U'] = true;
    um['V'] = true;
    um['W'] = true;
    um['X'] = true;
    um['Y'] = true;
    um['Z'] = false;
    bool impos = false;
    int i = 0;
    int j = n-1;
    while(i<j && !impos){
        if(word[i]!=word[j] || !um[word[i]] || !um[word[j]])
            impos = true;
        i++;
        j--;
    }
    if(!impos && um[word[mid]])
        cout<<"YES";
    else
        cout<<"NO";
    cout<<endl;

    return 0;
}
