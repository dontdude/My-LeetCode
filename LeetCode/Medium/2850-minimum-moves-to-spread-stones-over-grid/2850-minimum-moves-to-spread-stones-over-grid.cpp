class Solution {
public:
    int backTracking(int x, int y, int moves, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if(x >= m || y >= n) {
            return moves;
        }

        int next_x = x;
        int next_y = y + 1;
        if(next_y >= n) {
            next_x++;
            next_y = 0;
        }

        if(grid[x][y] > 0) return backTracking(next_x, next_y, moves, grid);

        int minNextMoves = INT_MAX;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 1) {
                    int addedMoves = abs(i - x) + abs(j - y);
                    
                    grid[x][y] = 1;
                    grid[i][j]--;

                    int nextMoves = backTracking(next_x, next_y, moves + addedMoves, grid);
                    minNextMoves = min(minNextMoves, nextMoves);

                    grid[x][y] = 0;
                    grid[i][j]++;
                }
            }
        }

        return minNextMoves;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        return backTracking(0, 0, 0, grid); 
    }
};