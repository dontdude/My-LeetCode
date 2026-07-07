class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int minPath = INT_MAX;

                if(i - 1 >= 0) minPath = min(minPath, grid[i - 1][j]);
                if(j - 1 >= 0) minPath = min(minPath, grid[i][j - 1]);

                if(minPath != INT_MAX)  grid[i][j] += minPath;
            }
        }   

        return grid[m - 1][n - 1];
    }
};