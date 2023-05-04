class Solution {
public:
    void printVec(vector< vector<int>> dp, int n){
      for(int i = 0; i<n;i++){
        for(int j = 0; j<n;j++){
          cout<<dp[i][j]<<" ";
        }
        cout<<endl;
      }
    }
    string longestPalindrome(string s){
      int n = s.size();
      vector<vector<int>> dp(n, vector<int>(n));
      pair<int, int> best;
      best.first = 0;
      best.second = 0;
      int maxDist = 0;

      for(int i = 0; i<n; i++){
        dp[i][i] = 1;
        if(i < n-1 && s[i] == s[i+1]){
          dp[i][i+1] = 1;
          best.first = i;
          best.second = i+1;
          maxDist = i+1 - i + 1;
        }
      }
      
      for(int j = 2; j<n;j++){
        for(int i = 0; i<n-1;i++){
          if(s[i] == s[j] && dp[i+1][j-1]==1){
            dp[i][j] = 1;
            if(maxDist < j - i + 1){
              best.first = i;
              best.second = j;
              maxDist = j - i + 1;
            }
          }
        }
      }
      //printVec(dp, n);
      //cout<<"bes(i, j): "<<best.first<<","<<best.second<<endl;
      //cout<<"maxDist: "<<maxDist<<endl;
      return s.substr(best.first, best.second - best.first + 1);
    }
};
