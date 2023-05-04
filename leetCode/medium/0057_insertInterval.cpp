class Solution {
public:
    int bs(vector<vector<int>> intervals, int s){
        int l = 0;
        int r = intervals.size()-1;
        int best_l_idx = -1;
        int best_l_val = -1;
        while(l<=r){
            int m = (l+r)/2;
            if(intervals[m][0] > s){
                r=m-1;
            }else{
                if(best_l_val <= intervals[m][0]){
                    best_l_val = max(best_l_val,intervals[m][0]);
                    best_l_idx = m;
                }
                l=m+1;
            }
        }
        return best_l_idx;
    }
    
    int bs2(vector<vector<int>> intervals, int s){
        int l = 0;
        int r = intervals.size()-1;
        int best_l_idx = -1;
        int best_diff = INT_MAX;
        while(l<=r){
            int m = (l+r)/2;
            int diff = abs(intervals[m][0]-s);
            if(intervals[m][0]==s){
                return m;
            }
            else if(intervals[m][0] > s){
                if(best_diff > diff){
                    best_diff = diff;
                    best_l_idx = m;
                }
                r=m-1;
            }else{
                if(best_diff > diff){
                    best_diff = diff;
                    best_l_idx = m;
                }
                l=m+1;
            }
        }
        return best_l_idx;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0) return {newInterval};
        vector<vector<int>> ans;
        
        // potential position for newInterval
        int id1 = bs(intervals,newInterval[0]);
        int id2 = bs(intervals,newInterval[1]);
        cout<<"id1="<<id1<<"; id2="<<id2<<endl;
    
        // exists overlap?
        bool impos = false;

        // not overlap or newIntegral is in id1/id2
        if(id1==id2 && id1!=-1){
            // contain?
            // left or right from the position id1/id2
            cout<<"intervals[id1][0]="<<intervals[id1][0]<<"; newInterval[0]="<<newInterval[0]<<endl;
            cout<<"intervals[id1][1]="<<intervals[id1][1]<<"; newInterval[1]="<<newInterval[1]<<endl;
            if(intervals[id1][1]<newInterval[0]){
                // not overlap && go to right
                impos=true;
                id1++;
            }
            else if(intervals[id1][0]>newInterval[1]){
                // not overlap && go to right
                impos=true;
                id1--;
            }
        }else if(id1==-1 && id1==id2){
            impos=true;
        }

        cout<<"post not overlap check >> id1="<<id1<<"; id2="<<id2<<endl;
        cout<<"impos="<<impos<<endl;

        // newInterval is overlap
        if(!impos){
            // not found, must be on first place
            if(id1==-1) id1=0;
            // check if factible that interval or
            // is the adjacent
            if(intervals[id2][0]>newInterval[1]) id2--;
            if(intervals[id1][1]<newInterval[0]) id1++;

            // build new interval for overlap
            int f = min(intervals[id1][0],newInterval[0]);
            int s = max(intervals[id2][1],newInterval[1]);
            bool agg = true; // only agg one time

            for(int i=0;i<intervals.size();i++){
                if(i>=id1 && i<=id2 && agg){
                    agg=false;
                    ans.push_back({f,s});
                }else if(i>=id1 && i<=id2 && !impos){
                    continue;
                }else{
                    ans.push_back(intervals[i]);
                }
            }
        }else{
            if(id1==-1){
                ans.push_back(newInterval);
                for(int i=0;i<intervals.size();i++){
                    ans.push_back(intervals[i]);
                }
            }else if(id1==intervals.size()){
                for(int i=0;i<intervals.size();i++){
                    ans.push_back(intervals[i]);
                }
                ans.push_back(newInterval);
            }else{
                for(int i=0;i<intervals.size();i++){
                    if(id1==i) ans.push_back(newInterval);
                    ans.push_back(intervals[i]);
                }
            }
        }
        return ans;
    }
};

