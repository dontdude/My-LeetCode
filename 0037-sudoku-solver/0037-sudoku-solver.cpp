class Solution {
public:
    // 1. Find any empty cell 
    // 2. fill it with valid number, and make a recursive call 
    // 4. if no valid number exsist, or recursive call returns false for every valid entry, returns false 
    void solveSudoku(vector<vector<char>>& board) {
        if(board.size() == 0)  return;
        solve(board);
    }

    bool solve(vector<vector<char>>& board){
        int i, j;
        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                if(board[i][j] == '.')  goto emptyCellFound;
            }
        }
        return true;

        emptyCellFound : 
        
        vector<bool> validNumbers(10, true);    // validNumbers[i] = true, if i can be valid entry for current empty cell
        checkValidNumbers(board, validNumbers, i, j);

        for(int k = 1; k <= 9; k++){
            if(validNumbers[k]){
                board[i][j] = (char)(k + '0');
                if(solve(board))  return true;
                board[i][j] = '.';         
            }
        }
        
        return false;
    }

    void checkValidNumbers(vector<vector<char>>& board, vector<bool>& validNumbers, int i, int j){
        for(int k = 0; k < 9; k++){            // checking row and columns of empty cell
            if(board[i][k] != '.')  validNumbers[board[i][k] - '0'] = false;
            if(board[k][j] != '.')  validNumbers[board[k][j] - '0'] = false;
        }

        int rs = i - i % 3;                    // checking subgrid of empty cell
        int cs = j - j % 3;                    // Starting indexes of the subgrid of size 3
        for(int x = 0; x < 3; x++){           
            for(int y = 0; y < 3; y++){
                if(board[x + rs][y + cs] != '.')  validNumbers[board[x + rs][y + cs] - '0'] = false;
            }
        }
    }
};