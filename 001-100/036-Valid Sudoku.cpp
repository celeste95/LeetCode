class Solution {//mine
private:
    vector<vector <vector <bool>>> num_valid;
    bool insert(int row,int col,char c)
    {
        if(c='.') return true;
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
                    num_valid[row/3+i][col/3+j][c-'1']=false;
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

class Solution
{//example
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
        
        return true;
    }
};