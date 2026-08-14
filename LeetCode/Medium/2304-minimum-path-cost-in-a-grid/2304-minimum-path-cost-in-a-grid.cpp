class Solution {
    int m, n;
    int dfs(int row, int col, vector<vector<int>>& dp, vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        if(dp[row][col] != -1)  return dp[row][col];
        if(row == m - 1) return dp[row][col] = grid[row][col];

        int minNextCost = INT_MAX;
        for(int nextCol = 0; nextCol < n; nextCol++) {
            int nextCost = moveCost[grid[row][col]][nextCol] + dfs(row + 1, nextCol, dp, grid, moveCost);
            minNextCost = min(minNextCost, nextCost);
        }

        return dp[row][col] = grid[row][col] + minNextCost;
    }
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        m = grid.size(), n = grid[0].size();
        int minCost = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int col = 0; col < n; col++) {
            minCost = min(minCost, dfs(0, col, dp, grid, moveCost));
        }

        return minCost;
    }
};