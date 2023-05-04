class Solution {
public:
    void getp(vector<set<string>>&ans, int it, int n){
        if(it<n){
            bool debugme=false;
            set<string> c_old = ans[it-1];
            int m=c_old.size();
            set<string> c;
            string op, cme;
            // loop every inst unique for previous ans
            if(debugme) cout<<"it="<<it<<endl;
            for(auto str : c_old){
                if(debugme) cout<<"str="<<str<<endl;
                // create new ans unique for ith str
                c.insert("()"+str);
                for(int i=0;i<str.length();i++){
                    cme=str;
                    cme.insert(i,"()");
                    if(debugme) cout<<"cme="<<cme<<endl;
                    c.insert(cme);
                }
            }
            if(debugme) cout<<"------------"<<endl;
            ans.push_back(c);
            getp(ans,it+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<set<string>> ans;
        set<string>t;
       bool debugme=false;
        t.insert("()");
        ans.push_back(t);
        getp(ans,1,n);
        vector<string> f;
        if(debugme) cout<<"[";
        for(auto str: ans[n-1]){
            if(debugme) cout<<str<<" ";
            f.push_back(str);
        }
        if(debugme) cout<<"]"<<endl;
        return f;
    }
}; 
