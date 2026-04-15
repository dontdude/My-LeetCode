class Solution {
    int m, n;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    bool isSafe(int i, int j) {
        return (i >= 0 && i < m) && (j >= 0 && j < n);
    }

    void bfsMarkSafe(int i, int j, vector<vector<char>>& board) {
        queue<pair<int, int>> q;

        q.push({i, j});
        board[i][j] = 'S';

        while(!q.empty()) {
            pair<int, int> cell = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int x = cell.first + dx[k];
                int y = cell.second + dy[k];

                if(isSafe(x, y) && board[x][y] == 'O') {
                    q.push({x, y});
                    board[x][y] = 'S';
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();

        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O')  bfsMarkSafe(i, 0, board);
            if(board[i][n - 1] == 'O')  bfsMarkSafe(i, n - 1, board);
        }

        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O')  bfsMarkSafe(0, j, board);
            if(board[m - 1][j] == 'O')  bfsMarkSafe(m - 1, j, board);
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'S') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};