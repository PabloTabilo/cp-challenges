
class Solution {
public:
    void pv(vector<int> v){
        for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        cout<<endl;
    }
    void combinations(vector<int> nums, map<int,bool> & mem ,vector<int> & comb, vector<vector<int>> &ans, int n){
        
        if(comb.size()==n) ans.push_back(comb);

        for(int i=0;i<n;i++){
            if(!mem[nums[i]]){
                comb.push_back(nums[i]);
                mem[nums[i]]=true;
                combinations(nums, mem, comb, ans, n); 
                comb.pop_back(); // backtracking
                mem[nums[i]]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> comb;
        map<int,bool> mem;
        for(int i=0;i<nums.size();i++) mem[nums[i]]=false;
        combinations(nums, mem, comb, ans, nums.size());
        return ans;
    }
};

