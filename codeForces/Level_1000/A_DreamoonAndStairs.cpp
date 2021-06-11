#include<iostream>
#include<stack>

using namespace std;

stack<int> s1;

void giveMePaths(int n, int steps){
   // cout<<"n: "<<n<<" steps: "<<steps<<endl;
    if(n <= 0){
        steps += 0;
        s1.push(steps);
    } else if(n == 1){
        steps +=1;
        s1.push(steps);
    }else{
        steps += 1;
        giveMePaths(n-1, steps);
        giveMePaths(n-2, steps);
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    int dp[n];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    int minSteps = 999999;
    int size_1;
    if(n%2 == 0)
        size_1 = n/2;
    else
        size_1 = (n/2)+1;
    for(int i = n; i>= size_1; i--){
        if(i%m == 0){
            minSteps = min(minSteps, i);
        }
    }
    if(minSteps != 999999)
        cout<<minSteps<<endl;
    else
        cout<<-1<<endl;
    /*
    giveMePaths(n, 0);
    int minSteps = 999999;
    bool multM = false;
    while(!s1.empty()){
        int sv = s1.top();
        //cout<<sv<<endl;
        if(sv%m==0){
            multM = true;
            minSteps = min(minSteps, sv);
        }
        s1.pop();
    }
    if(!multM){
        cout<<-1<<endl;
    }else{
        cout<<minSteps<<endl;
    }
    */
    return 0;
}
