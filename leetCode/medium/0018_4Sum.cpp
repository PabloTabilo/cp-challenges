typedef long long ll;

class Solution {
public:
    void pv(vector<int> v){
        cout<<endl;
        for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        cout<<endl;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> t(4);
        bool debugme=false;
        int k,l;
        ll s,c;
        map<vector<int>,bool> dp;
        unordered_map<ll, vector<pair<int,int>>> mymap;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                s = nums[i]+nums[j];
                mymap[s].push_back(make_pair(i,j));
            }
        }
        
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue; // pesca el primer par i,j no duplicado
                //if(debugme) cout<<"nums[i]="<<nums[i]<<"; nums[j]="<<nums[j]<<endl;
               s = nums[i]+nums[j];
                c = target-s;
                //if(debugme) cout<<"s="<<s<<"; c="<<c<<"; target="<<target<<endl;
                if(mymap.find(c)!=mymap.end()){
                    for(int w=0;w<mymap[c].size();w++){
                        k = mymap[c][w].first;
                        l = mymap[c][w].second;
                        
                        t[0]=nums[k];
                        t[1]=nums[l];
                        
                        t[2]=nums[i];
                        t[3]=nums[j];
                        
                        
                        set<int> diff;
                        diff.insert(i);
                        diff.insert(j);
                        diff.insert(k);
                        diff.insert(l);
                        sort(t.begin(),t.end());
                        
                        if(debugme) pv(t);
                        if(dp.find(t)==dp.end() && diff.size() == 4){
                            ans.push_back(t);
                            dp[t]=true;
                        }
                    }
                }
                //if(debugme) cout<<"map[s].push_back(<"<<i<<","<<j<<">)"<<endl;
                //if(debugme) cout<<"------------------------------"<<endl;
            }
        }
        return ans;
    }
}; 
