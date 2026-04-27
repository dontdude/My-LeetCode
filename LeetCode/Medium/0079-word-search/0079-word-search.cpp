class Solution {
    int m, n;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool isSafe(int x, int y) {
        return (x >= 0 && x < m) && (y >= 0 && y < n);
    }
    bool dfs(int c, int i, int j, string& word, vector<vector<char>>& board) {
        c++;
        if(c == word.size())  return true;

        char orgChar = board[i][j];
        board[i][j] = '.';

        for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if(isSafe(x, y) && board[x][y] == word[c]) {
                if(dfs(c, x, y, word, board)) {
                    board[i][j] = orgChar;
                    return true;
                }
            }
        }

        board[i][j] = orgChar;

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(0, i, j, word, board))  return true;
                }
            }
        }

        return false;
    }
};