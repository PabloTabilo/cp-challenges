class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // space: O(n*k)
        vector<vector<string>> res;
        int n = strs.size();
        // space: O(n*k)
        map<string,vector<string>> m;
        string s1;
        // O(n*klogk)
        for(int i=0;i<n;i++){
            s1 = strs[i]; // strs[i] - original
            sort(strs[i].begin(),strs[i].end()); // strs[i] direccion - sorted.
            m[strs[i]].push_back(s1);
        }
        for(auto x : m) res.push_back(x.second);

        return res;
    }
};
