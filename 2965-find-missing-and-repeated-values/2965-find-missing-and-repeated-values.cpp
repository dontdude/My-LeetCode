class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> res(2, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int curr = abs(grid[i][j]) - 1;
                int r = curr / n, c = curr % n;
                grid[r][c] = -1 * grid[r][c];

                if(grid[r][c] > 0) {
                    res[0] = curr + 1;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0) {
                    int possibleMissing = (n * i) + j + 1;
                    if(res[0] != possibleMissing) {
                        res[1] = possibleMissing;
                        return res;
                    }
                }
            }
        }

        return res;
    }
};