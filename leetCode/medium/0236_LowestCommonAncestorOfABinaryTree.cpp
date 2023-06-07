/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode *> nodes;
    vector<int> depth;
    unordered_map<int, int> last;
    int num_nodes = 0;

    void pv(vector<int> v){
        cout<<endl<<"{ ";
        for(auto x : v){
            cout<<x<<" ";
        }
        cout<<"}"<<endl;
    }

    void pv2(vector<vector<int>> v){
        for(auto x : v){
            for(auto y : x){
                cout<<y<<" ";
            }
            cout<<endl;
        }
    }

    void eulerian_tour(TreeNode * root, int deep){
        nodes.push_back(root);
        depth.push_back(deep);
       
        if(root->left){
            eulerian_tour(root->left, deep+1);
            nodes.push_back(root);
            depth.push_back(deep);
        }

        num_nodes++;
        
        if(root->right){
            eulerian_tour(root->right, deep+1);
            nodes.push_back(root);
            depth.push_back(deep);
        }
    }

    void create_sparse_table(vector<vector<int>> & st, vector<vector<TreeNode *>> & sti){
        int m = st.size();
        int n = st[0].size();

        for(int i=1;i<m;i++){
            for(int j=0; j+(1<<i)-1 < n; j++){
                st[i][j] = min(st[i-1][j], st[i-1][j+(1<<(i-1))]);
                if(st[i-1][j] < st[i-1][j+(1<<(i-1))]){
                    sti[i][j] = sti[i-1][j];
                }else{
                    sti[i][j] = sti[i-1][j+(1<<(i-1))];
                }
            }
        }
    }

    TreeNode * rmq(vector<vector<int>> st,vector<vector<TreeNode *>> sti, int ll, int lr){
        int l = min(ll,lr);
        int r = max(ll,lr);
        int p = 0;
        int len = r - l + 1;
        for(int i=0; 1<<(i+1) <= len;i++){
            p++;
        }
        if(st[p][l] < st[p][r - (1<<p) + 1]){
            return sti[p][l];
        }
        return sti[p][r - (1<<p) + 1];
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Eulerian tour
        //         0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
        // nodes = 3 5 6 5 2 7 2 4 2 5  3  1  0  1  8
        // depth = 0 1 2 1 2 3 2 3 2 1  0  1  2  1  2
        // O(E+V)
        eulerian_tour(root,0);
    
        //         0  1  2  3  4  5  6  7  8
        // last {hash} =  12 13 8 10  7  9  2  5  14
        // cant start in any -1e9 <= node.val <= 1e9 
        // O(E+V)
        int n = nodes.size();
        for(int i=n-1;i>=0;i--){
            if(last.find(nodes[i]->val) == last.end()){
                last[nodes[i]->val] = i;
            }
        }
 
        int m = 0;
        for(int i=0; 1<<i <= n;i++){
            m++;
        }

        vector<vector<int>> st(m, vector<int>(n, 1e5+1));
        vector<vector<TreeNode *>> sti(m, vector<TreeNode *>(n, NULL));
        for(int i=0;i<n;i++){
            st[0][i] = depth[i];
            sti[0][i] = nodes[i];
        }
        // O((E+V) log (E+V)) = O(n log n)
        create_sparse_table(st,sti);
        // O(log(E+V))
        return rmq(st,sti,last[p->val],last[q->val]);
        // SparseTable
        // DP ((V+E) * log (V+E))
        //         0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
        // RMQ = 0 0 1 2 1 2 3 2 3 2 1  0  1  2  1  2
        //       1 0 1 1 1 2 2 2 2 1 0  0  1  1  1  X
        //       2 0 1 1 1 2 2 1 0 0 0  0  1  X  X  X
        //       3 0 1 0 0 0 0 0 0 X X  X  X  X  X  X
         
    }
};
