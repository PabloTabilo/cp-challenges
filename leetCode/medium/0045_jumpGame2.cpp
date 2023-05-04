class Solution {
public:
    void pv(vector<int> v){
        int n=v.size();
        for(int i=0;i<n;i++) cout<<v[i]<<" ";
        cout<<endl;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        int MY_MAX=1e4;
        bool debugme=true;
        vector<int> dp(n,MY_MAX);
        dp[n-1]=0;
        int b;
        for(int i=n-2;i>=0;i--){
            //if(debugme) cout<<"i="<<i<<"; dp[i]="<<dp[i]<<"; nums[i]="<<nums[i]<<endl;
            if(nums[i]==0) continue;
            // 0 <= j <= nums[i]
            // tengo q moverme 1
            // 1 <= j <= nums[i]
            dp[i]=dp[i+1];
            for(int j=2;j<=nums[i];j++){
                if(i+j>=n) break;
                dp[i]=min(dp[i+j],dp[i]);
            }
            dp[i]++;
            //if(debugme) pv(dp); 
        }
        //if(debugme) pv(dp);
        return dp[0];
    }
};
