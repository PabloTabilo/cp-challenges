class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1,0);
	dp[n] = 1; // init with 1 for pass combination to other valids paths
        for(int i=n-1;i>=0;i--){
            if(s[i] != '0'){
                // enter here always is valid
                // dp[i] : #combinations valids with i
                dp[i] = dp[i+1];
		if(i<n-1 && (s[i]=='1' || s[i]=='2' && s[i+1]<'7')){
		    dp[i] += dp[i+2];
		}
            }
        }
        return dp[0];
    }
};
