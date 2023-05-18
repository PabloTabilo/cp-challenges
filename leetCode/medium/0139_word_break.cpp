class Solution {
public:
    void pv(vector<string> v){
        cout<<endl<<"{ ";
        for(auto s : v){
            cout<<s<<" ";
        }
        cout<<"}"<<endl;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<char,vector<string>> um;
        for(auto x : wordDict){
            um[x[0]].push_back(x);
        }
        // k = 0
        // catsandog
        // words that starts with s[k] are factible
        // 0 cat >> sandog
        // 1 cats >> andog

        // 0 -> sandog
        // 0.0 sand >> og

        // 1 -> andog
        // 1.0 and >> og

        // 0.0 og -> IMPOS

        // 1.0 og -> IMPOS
        int k = 0;
        bool impos = false;
        queue<int> qk;
        qk.push(k); 

        vector<bool> dp(s.length()+1,true);

        while(!qk.empty()){
            k = qk.front();
            qk.pop();
            //cout<<"k = "<<k<<endl;
            if(!dp[k]){
                continue;
            }

            if(k==s.length()){
                return true;
            }
            // words that start with s[k] are factible
            vector<string> cs = um[s[k]];
            //pv(cs);
            
            // evaluate candidate
            bool no_valid_any_candidate = false;
            for(auto c : cs){
                impos = false;
                for(int i=0;i<c.length();i++){
                    //cout<<"s[k+i],c[i] = "<<s[k+i]<<","<<c[i]<<endl;
                    if(s[k+i]!=c[i]){
                        impos = true;
                        break;
                    }
                }
                if(!impos){
                    //cout<<" valid neigh !"<<endl;
                    no_valid_any_candidate = true;
                    qk.push(k+c.length()); // start from position of new word
                }
            }
            if(!no_valid_any_candidate){
                dp[k] = false;
            }
            //cout<<"--------------------------"<<endl;
        }
        return false;
    }
};
