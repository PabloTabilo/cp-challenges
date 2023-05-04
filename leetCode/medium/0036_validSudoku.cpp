// https://leetcode.com/problems/valid-sudoku/
class Solution {
public:
    void reboot_me(vector<int> & val){
        for(int i=0;i<10;i++) val[i]=0;
    }
    bool val_row(vector<vector<char>> board){
        vector<int> val(10,0);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int c=board[i][j];
                if(c!='.') val[c-'0']++;
                if(c!='.' && val[c-'0']>1) return false;
            }
            reboot_me(val);
        }
        return true;
    }

    bool val_col(vector<vector<char>> board){
        vector<int> val(10,0);
        for(int j=0;j<9;j++){
            for(int i=0;i<9;i++){
                int c=board[i][j];
                if(c!='.') val[c-'0']++;
                if(c!='.' && val[c-'0']>1) return false;
            }
            reboot_me(val);
        }
        return true;
    }

    bool val_sub(vector<vector<char>> board){
        int i=0;
        int j=0;
        vector<int> val(10,0);
        while(i<9 && j+3<=9){
            int n=i+3;
            int m=j+3;
            for(nt k=i;k<n;k++){
                for(int w=j;w<m;w++){
                    int c=board[k][w];
                    if(c!='.') val[c-'0']++;
                    if(c!='.' && val[c-'0']>1) return false;     
                }
            }
            i+=3;
            if(i>=9){
                j+=3;
                i=0;
            }
            reboot_me(val); 
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool r = val_row(board);
        bool c = val_col(board);
        bool s = val_sub(board);
        return r && c && s;
    }
};
