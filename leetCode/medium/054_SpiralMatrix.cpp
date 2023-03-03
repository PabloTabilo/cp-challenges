class Solution {
public:
    bool traversal(vector<vector<int>>matrix,int n,int m,int i,int j, vector<vector<bool>> &v,vector<int> &ans, bool &l, bool &b, bool &r, bool &u){
        //cout<<"i: "<<i<<"; j:"<<j<<endl;
        if(i<0 || j<0 || i>=n || j>=m) return false;
        if(v[i][j]) return false;

        //cout<<"matrix[i][j]: "<<matrix[i][j]<<endl;
        
        ans.push_back(matrix[i][j]);
        v[i][j]=true;
        
        while(l){
            l = traversal(matrix,n,m,i,j+1,v,ans,l,b,r,u);
        }
        while(b && !l){
            b = traversal(matrix,n,m,i+1,j,v,ans,l,b,r,u);
        }
        while(!b && r){
            r = traversal(matrix,n,m,i,j-1,v,ans,l,b,r,u);
        }
        while(!r && u){
            u = traversal(matrix,n,m,i-1,j,v,ans,l,b,r,u);   
        }
        //cout<<"if try"<<endl;
        //cout<<"matrix[i][j]: "<<matrix[i][j]<<endl;
        //cout<<"l: "<<l<<"; b: "<<b<<"; r: "<<r<<"; u: "<<u<<endl;
        //cout<<"ans.size(): "<<ans.size()<<endl;
        if(!l && !b && !r && !u && ans.size() < n*m){
            //cout<<"if reboot"<<endl;
            l=true;
            b=true;
            r=true;
            u=true;
            traversal(matrix,n,m,i,j+1,v,ans,l,b,r,u);
        }
        return false;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> ans;
        vector<vector<bool>>v(n,vector<bool>(m,false));

        bool l=true;
        bool r=true;
        bool b=true;
        bool u=true;
       
        traversal(matrix,n,m,0,0,v,ans,l,b,r,u); // O(V+E)
        return ans;
    }
};
