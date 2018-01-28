class Solution {
private:
    void dfs(vector<vector<char>>& board, int i, int j, char ch) {
        if(i<0||j<0||i>=board.size()||j>=board[0].size()) return;
        if(board[i][j]!='O') return;
        board[i][j]=ch;
        dfs(board,i+1,j,ch);
        dfs(board,i,j+1,ch);
        dfs(board,i-1,j,ch);
        dfs(board,i,j-1,ch);
    }
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0) return;
        if(board[0].size()==0) return;
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<row;i++) {
            if(board[i][0]=='O') dfs(board,i,0,'a');
            if(board[i][col-1]=='O') dfs(board,i,col-1,'a');
        }
        for(int i=0;i<col;i++) {
            if(board[0][i]=='O') dfs(board,0,i,'a');
            if(board[row-1][i]=='O') dfs(board,row-1,i,'a');
        }
        // for(int i=0;i<board.size();i++) {
        //     for(int j=0;j<board[i].size();j++) {
        //         if(board[i][j]=='O') dfs(board,i,j,'X');
        //     }
        // }
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++) {
                if(board[i][j]=='O') board[i][j]='X';//这句代替上面的注释部分 此句和注释二选一
                if(board[i][j]=='a') board[i][j]='O';
            }
        }
    }
};
