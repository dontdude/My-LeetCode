class Solution {
public:
    // Recurrence Relation:
    // rec(i, j)  // i = 0 -> i = n -1, j = 0 -> j = m-1
    //    if(i == n - 1 && j == m - 1)  return grid[i][j] // base case
    //    if i >= n-1 || j >= m - 1 ->  return INT_MAX // to depit path not possible
       
    //    int path = min(rec(i + 1, j), rec(i, j + 1));

    //    int minCurPath = INT_MAX;
    //    if(path != INT_MAX) {
    //       minCurPath = min(minCurPath, grid[i][j] + path)
    //    }

    //    return minCurPath

    // Tabulation (directly from recurrence, i = n - 1 -> 0, j = m -1 -> 0)
    int minPathSum(vector<vector<int>>& grid) {
       int n = grid.size(), m = grid[0].size();

       vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
       dp[n-1][m-1] = grid[n-1][m-1];

       for(int i = n - 1; i >= 0; i--) {
          for(int j = m - 1; j >= 0; j--) {
            int path = min(dp[i + 1][j], dp[i][j + 1]);

            if(path != INT_MAX) {
                dp[i][j] = min(dp[i][j], grid[i][j] + path);
            }
          }
       } 

       return dp[0][0];
    }
};