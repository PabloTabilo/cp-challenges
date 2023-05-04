// https://leetcode.com/problems/next-permutation/
class Solution {
public:
    void swap_me(vector<int> &nums, int k, int l){
        int t = nums[k];
        nums[k]=nums[l];
        nums[l]=t;
    }
    void reverse_me(vector<int>&nums, int f, int to){
        int i=f;
        int j=to;
        while(i < j){
            //cout<<"nums[i]="<<nums[i]<<"; nums[j]="<<nums[j]<<endl;
            swap_me(nums,i,j);
            //cout<<"nums[i]="<<nums[i]<<"; nums[j]="<<nums[j]<<endl;
            //cout<<"----------"<<endl;
            i++;
            j--;
        }
    }
    void pv(vector<int>v){
        for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        cout<<endl;
    }
    void nextPermutation(vector<int>& nums) {
        // req
        // 1. replace in place
        // 2. O(1) space complex
        
        int n = nums.size();
        int k = n-2;
        while(k>=0 && nums[k] >= nums[k+1]){
            k--;
        }
        
        //cout<<"k="<<k<<endl;
        
        if(k<0){
            reverse_me(nums, 0, n-1);
        }else{
            int ln-1; // inmediate more bigger than k
            while(l>k && nums[k] >= nums[l]){
                l--;
            }
            //cout<<"l="<<l<<endl;
            swap_me(nums,k,l);
            //pv(nums);
            reverse_me(nums,k+1,n-1);
        }
        
    }
};
