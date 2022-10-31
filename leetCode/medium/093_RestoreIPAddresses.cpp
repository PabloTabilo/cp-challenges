class Solution {
public:
    vector<stack<string>> vc;
    void comb(stack<string> mystack,int n,int depth){
        if(n==0 && depth==4){
            vc.push_back(mystack);
        }
        if(n>0 && depth!=4){
            mystack.push("1");
            comb(mystack,n-1,depth+1);
            mystack.pop();
            
            mystack.push("2");
            comb(mystack,n-2,depth+1);
            mystack.pop();
            
            mystack.push("3");
            comb(mystack,n-3,depth+1);
            mystack.pop();
        }
    }
    
    bool validateMe(string p){
        // prepend 0s? and len > 1
        if(p.size()>1 && p[0]=='0') return false;
        // over 255?
        int num = stoi(p);
        if(num>255) return false;
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string>res;
        stack<string> mystack;
        comb(mystack,s.length(),0);
        int n = vc.size();
        for(int i=0;i<n;i++){
            string myans="";
           int j=0;
            bool isValid = true;
            while(!vc[i].empty()){
                string d = vc[i].top();
                //cout<<d<<" ";
                int ite=stoi(d);
                string p = "";
                //cout<<"ite="<<ite<<endl;
                while(ite>0 && j<s.size() && isValid){
                    p+=s[j];
                    j+=1;
                    ite-=1;
                }
                //cout<<"p="<<p<<endl;
                if(p!="") isValid = validateMe(p);
                else isValid=false;
                //cout<<"isValid="<<isValid<<endl;
                vc[i].pop();
                if(!vc[i].empty()) p+=".";
                if(isValid) myans+=p;
            }
            //cout<<"myans="<<myans<<endl;
            if(isValid) res.push_back(myans);
            //cout<<"---------------------"<<endl;
            //cout<<endl;
        }
        return res;
    }
}; 
