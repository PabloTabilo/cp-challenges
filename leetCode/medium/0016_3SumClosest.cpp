class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int res = 1e9+1;
        int j,k;
        for(int i=0;i<n-2;i++){
            j=i+1;
            k=n-1;
            while(j<k){
                int c = nums[i] + nums[j] + nums[k];
                if(c > target) k--;
                else j++;
                if(abs(c-target)<abs(res-target)) res=c;
            }
        }
        return res;
    }
};
