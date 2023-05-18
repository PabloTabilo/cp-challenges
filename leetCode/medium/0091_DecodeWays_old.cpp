class Solution {
public:
    map<string,char> mm;
    Solution(){
        string k; 
        char v;
        int ii=1;
        for(int i=0;i<26;i++){
            k = to_string(i+1);
            v = 'A'+i;
            mm[k]=v;
        }
    }
    
    void loop(vector<int> v){
        cout<<endl<<"{ ";
        for(auto x : v){
            cout<<x<<" ";
        }
        cout<<"}"<<endl;
    }
    
    int numDecodings(string s) {
        int ans = 0;
        int n = s.length();
        vector<int> dp(n,0);
        string p;
        for(int i=n-1;i>=0;i--){
            p = "";
            p += s[i];
            if(mm[p]){
                if(i == n-1){
                    dp[i]++;
                }else{
                    dp[i]+=dp[i+1];
                }
            }
            if(i+1<n){
                p+=s[i+1];
                if(mm[p]){
                    if(i == n-2){
                        dp[i]++;
                    }else{
                        dp[i]+=dp[i+2];
                    }
                }
            }
        }
        //loop(dp);
        return dp[0];
    }
};
