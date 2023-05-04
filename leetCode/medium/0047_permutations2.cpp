class Solution {
public:
    void combinations(vector<int> nums, vector<int>& comb, vector<vector<int>> &ans, vector<bool> vis, int n){
        if(comb.size() == n){
            ans.push_back(comb);
            return;
        } 
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                comb.push_back(nums[i]);
                vis[i]=true;
                
                combinations(nums,comb,ans,vis,n);
                
                comb.pop_back();
                vis[i]=false;
            }
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans, res;
        int n = nums.size();
        vector<bool> vis(n,false);
        vector<int> comb;
        set<vector<int>> exists;

        combinations(nums, comb, ans, vis, n); // o(n!) -> n*(n-1)*(n-2)*...*2*1
        
        // O(k * log k)
        // O(k) -> k: number of combinations
        for(int i=0;i<ans.size();i++){
            if(exists.find(ans[i])==exists.end()) // O(log n): Amortized
            {
                exists.insert(ans[i]);
                res.push_back(ans[i]);
            }
        }
        
        // O(n! + k*log k) = O(n!)

        return res;
    }
};
