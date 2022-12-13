class Solution {
public:
    int found_me(vector<int> nums, int t, int l, int r){
        if(l < r && l>=0 && r>=0){
            int m = (l+r)/2;
            if(nums[m]==t) return m;
            int ans_l=-1;
            int ans_r=-1;
            int n=nums.size();
            if(nums[l]<=t || (m-1>=0 && t<=nums[m-1])){
                ans_l=found_me(nums,t,l,m-1);
            }
            if((m+1<n && nums[m+1]<=t) || t<=nums[r]){
                ans_r=found_me(nums,t,m+1,r);
            }
            if(ans_l==-1 && ans_r==-1) return -1;
            else if(ans_l != -1) return ans_l;
            else return ans_r;
        }
        if(l>=0 && nums[l]==t) return l;
        if(r>=0 && nums[r]==t) return r;
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return found_me(nums,target,0,nums.size()-1);
    }
};
