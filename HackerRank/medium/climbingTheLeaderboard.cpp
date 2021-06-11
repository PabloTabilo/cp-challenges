#include <iostream>
#include <set>
#include <vector>
#include <iterator>

//https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

using namespace std;

int binary(vector<int> arr, int l, int r, int key){
    if(l < r){
        int m = (l + r)/ 2;
        if(arr[m] == key)
            return m;
        if(arr[m] < key)
            return binary(arr, l, m-1, key);
        else
            return binary(arr, m+1, r, key);
    }
    return l;
}

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    set<int, greater<int> > s1; 
    for(int i = 0; i < ranked.size(); i++){
        s1.insert(ranked[i]);    
    }
    int n = s1.size();
    vector<int> rank;
    
    for(set<int, greater<int> >::iterator it = s1.begin(); it != s1.end(); it++)
        rank.push_back(*it);
    //cout<<" llego";
    vector<int> vres;
    for(int i = 0; i < player.size(); i++){
        int res = binary(rank, 0, rank.size()-1, player[i]);
        //cout<<"player[i]: "<<player[i]<<" rank[res]: "<<rank[res]<<" res: "<<res<<" actual ans: ";
        if(player[i] < rank[res]){
            res += 2;
        }else if(player[i] >= rank[res]){
            res += 1;
        }
        //cout<<res<<endl;
        vres.push_back(res);
    }
    return vres;
}

int main()
{
    int rk[] = { 100, 90, 90, 80, 75, 60 };
    int n_rk = sizeof(rk) / sizeof(rk[0]);
    
    int pl[] = { 50, 65, 77, 90, 102 };
    int n_pl = sizeof(pl) / sizeof(pl[0]);
    
    vector<int> player(pl, pl + n_pl);
    vector<int> ranked(rk, rk + n_rk);
    vector<int> res;
    
    res = climbingLeaderboard(ranked, player);
    cout<<endl;
    for(auto x : res){
        cout<<x<<" ";
    }
    return 0;
}
