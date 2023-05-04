class Solution {
public:
    void printVec(vector<char> v){
        int n = v.size();
        for(int i = 0; i<n; i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    string convert(string s, int numRows) {
        bool debug = false;
        int interM = numRows - 2;
        int n = s.size();
        vector<char> vc(n);
        int i = 0, j = 0, k;
        int w = 0;
        if(interM < 0){
          return s;
        }
        if(debug) printVec(vc);
        while(i < numRows && j < n){
          if(debug){
            cout<<"i: "<<i<<endl;
            cout<<"w: "<<w<<endl;              
          }
          k = i;
          while(k < n){
            if(debug) printVec(vc);
            vc[j++] = s[k];
            if(debug) cout<<"k: "<<k<<endl;
            k+=numRows+interM;
            if(debug) cout<<"k new: "<<k<<endl;
            if(i != 0 && i != numRows-1 && k-w < n){
                if(debug) cout<<"can enter!, w : "<<w<<endl;
                vc[j++] = s[k - w];
           }
          }
          if(debug) printVec(vc);
          if(debug) cout<<"--------------------"<<endl;
          w+=2;
          i++;
        }
        if(debug) printVec(vc);
        string res(vc.begin(), vc.end());
        return res;
    }
}; 
