class Solution {
    int n;
    int s;
    int getBoxID(int row, int col) {
        int r = row - (row % s);
        int c = col / 3;
        return r + c;
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