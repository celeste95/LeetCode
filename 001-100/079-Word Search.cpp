class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(!board.size()) return false;
        if(!board[0].size()) return false;
        //vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        //queue<pair<int,int>> start_queue;
        char last_letter=word.back();
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
                if(board[i][j]==last_letter)
                {
                    //visited[i][j]=true;
                    word.pop_back();
                    if(backtrack(board, word, visited, i, j)) 
                        return true;
                    word.push_back(last_letter);
                    //visited[i][j]=false;
                }
            }
        }
        return false;
    }
private:
    bool backtrack(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int i, int j)
    {
        if(word.length()==0) return true;
        visited[i][j]=true;
        char last_letter=word.back();
        word.pop_back();
        if(j<board[0].size()-1 && board[i][j+1]==last_letter && !visited[i][j+1])
            if(backtrack(board, word, visited, i, j+1)) return true;
        if(i<board.size()-1 && board[i+1][j]==last_letter && !visited[i+1][j])
            if(backtrack(board, word, visited, i+1, j)) return true;
        if(j>0 && board[i][j-1]==last_letter && !visited[i][j-1])
            if(backtrack(board, word, visited, i, j-1)) return true;
        if(i>0 && board[i-1][j]==last_letter && !visited[i-1][j])
            if(backtrack(board, word, visited, i-1, j)) return true;
        return false;
    }
};