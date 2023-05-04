class Solution {
public:
    void pV(vector<int> v){
        int n=v.size();
        for(int i=0;i<n;i++) cout<<v[i]<<" ";
        cout<<endl;
    }
    vector<int> build_lps(string needle, int n){
        vector<int> lps(n,0);
        int i=1;
        int len=0;
        while(i < n){
            if(needle[i]==needle[len]){
                lps[i++] = len+1;
                len++;
            }else{
                if(len != 0) len = lps[len-1];
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        } 
        return lps;
    }
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> lps = build_lps(needle,m);
        //pV(lps);
        int i=0;
        int j=0;
        int res=-1;
        while(i < n && res==-1){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }else{
                if(j!=0) j = lps[j-1];
                ele i++;
            }
            if(j == m){
                res = i-j;
                j = lps[j-1];
            }
        }
        return res;
    }
};
