#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
*/
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 void bfs(TreeNode Tree){
   queue< TreeNode > q;
   q.push(Tree);
   int stopme = 10;
   int cnt = 1;
   while(!q.empty() && cnt < stopme){
        cnt++;
        TreeNode lastNode = q.front();
        q.pop();
        cout<<"val: "<<lastNode.val<<endl;
        cout<<"q.size(): "<<q.size()<<endl;
        if(lastNode.left != nullptr){
            TreeNode l = *lastNode.left;
            q.push(l);
            cout<<"have left!: "<<l.val<<endl;
        }else{
            cout<<"null"<<endl;
        }
        if(lastNode.right != nullptr){
            TreeNode r = *lastNode.right;
            q.push(r);
            cout<<"have right!: "<<r.val<<endl;
        }else{
            cout<<"null"<<endl;
        }
   }
 }
 
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        vector< vector<TreeNode> > dp(20); // Save structures
        vector< vector<TreeNode * > > leafs(20); // Save pointers to leaf nodes
        // root node
        TreeNode root = TreeNode();
        TreeNode copyRoot = root;
        // push root node on dp & on p vectors
        dp[1].push_back(copyRoot); // structure
        leafs[1].push_back(&root); // root is leaf
        int myCount = 0;
        for(int i=3; i < n; i+=2){// Version previa
            // Pass for each previous structure build
            cout<<"dp build: "<<i<<endl;
            // Get all leaf nodes
            // Assign for each leaf left & right nodes.
            cout<<"leafs size: "<<leafs[i-2].size()<<endl;
            for(int k = 0; k < leafs[i-2].size(); k++){ // all leaf por set de BT validos
                TreeNode * mypointer = leafs[i-2][k];
                cout<<"current leaf: "<<mypointer->val<<endl;
                // Create left & right nodes
                TreeNode l = TreeNode(++myCount);
                TreeNode r = TreeNode(++myCount);
                // Assign
                mypointer->left = &l;
                mypointer->right = &r;
                cout<<"new values for l, r: "<<l.val<<","<<r.val<<endl;
                // Save to dp[i] the new structure
                TreeNode copyTree = *mypointer;
                dp[i].push_back(copyTree);
                // Save pointers
                leafs[i].push_back(copyTree.left);
                leafs[i].push_back(copyTree.right);
                // eliminate changes, using copys
            }
        }
        //for(int i = 1; i<n; i+=2){
        //    cout<<"i: "<<i<<endl;
        //    if(dp[i].size()>0){
        //        for(int j = 0; j < dp[i].size();j++){
        //            bfs(dp[i][j]);
        //        }
        //    }else cout<<"Nothing"<<endl;
        //}
        cout<<"dp[1][0]"<<endl;
        bfs(dp[1][0]);
        cout<<"dp[3][0]"<<endl;
        bfs(dp[3][0]);
        //bfs(dp[5]);
        return ans;
    }
};

void solution(){
    int n;
    cout<<"Size of the tree: ";
    cin>>n;
    Solution sol = Solution();
    vector<TreeNode *> ans = sol.allPossibleFBT(n);
    cout<<endl;
}

int main() {
    int t;
    cout<<"number of repetitions: ";
    cin>>t;
    while(t--){
        solution();
    }
}
