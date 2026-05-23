class Solution {
    int n;
    int s;
    int getBoxID(int row, int col) {    // 2d index -> 1d index of smaller sub grid
        int row_id = row / 3;   // gives us => 0, 1 or 2
        int col_id = col / 3;   // gives us => 0, 1 or 2
        int box_id = (row_id * 3) + col_id;   // (0, 3, 6) + (0, 1, 2) => (0, 1, 2, ... 8)
        return box_id;
    }
public:
    Solution() {
        n = 9;
        s = 3;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(n);
        vector<unordered_set<char>> col(n);
        vector<unordered_set<char>> box(n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '.')  continue;

                char num = board[i][j];

                int boxID = getBoxID(i, j);

                if((row[j].find(num) != row[j].end()) || (col[i].find(num) != col[i].end()) || (box[boxID].find(num) != box[boxID].end()))  return false;

                row[j].insert(num);
                col[i].insert(num);
                box[boxID].insert(num);
            }
        }

        return true;
    }
};