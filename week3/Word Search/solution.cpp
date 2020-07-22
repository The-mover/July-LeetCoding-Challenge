class Solution {
private:
    bool dfs(vector<vector<char>>& board, string& word, int index, int i, int j) {
        if( index == word.size() ) return true;
        if( i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || word[index] != board[i][j] ) return false;   
        
        board[i][j] = '#';
        if( dfs(board, word, index + 1, i+1, j) ||
            dfs(board, word, index + 1, i-1, j) ||
           dfs(board, word, index + 1, i, j+1) ||
           dfs(board, word, index + 1, i, j-1)
          ) return true;
        
        board[i][j] = word[index];
        
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if( board[i][j] == word[0] && dfs(board, word, 0, i, j) )
                    return true;
            }
        }
        return false;
    }
};