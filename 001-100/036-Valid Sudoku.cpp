class Solution {
private:
    vector<vector <vector <bool>>> num_valid;
    bool insert(int row,int col,char c)
    {
        if(c=='.') return true;
        if(!num_valid[row][col][c-'1']) return false;
        else
        {
            for(int i=0;i<9;i++)
            {
                num_valid[i][col][c-'1']=false;
                num_valid[row][i][c-'1']=false;
            }
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    num_valid[row/3*3+i][col/3*3+j][c-'1']=false;
                }
            }
            return true;
        }
    }
public:
    Solution(): num_valid(9,vector<vector <bool>>(9,vector<bool>(9,true))) {}
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(!insert(i,j,board[i][j])) return false;
            }
        }
        return true;
    }
};
