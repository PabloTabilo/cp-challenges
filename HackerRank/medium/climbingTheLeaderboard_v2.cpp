#include <iostream>
#include <set>
#include <vector>
#include <iterator>

//https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

using namespace std;

#define LIMIT 1000000001

int A[LIMIT] = {0};

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    int myRank = 1;
    int n_ranked = ranked.size();
    for(int i = 0; i < n_ranked; i++){
        if(A[ranked[i]] == 0)
            A[ranked[i]] = myRank++;
        //cout<<"ranked[i]: "<<ranked[i]<<" - ";
        //cout<<"A[ranked[i]]: "<<A[ranked[i]]<<endl;
    }
    int val = myRank;
    for(int i = 0; i < LIMIT; i++){
        if(A[i] != 0){
            val = A[i];
        }
        A[i] = val;
    }
    int m = player.size();
    vector<int> vres(m);
    for(int i = 0; i < m; i++){
        vres[i] = A[player[i]];
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
