class Solution {
    private int m;
    private int n;
    private int[] dx = {1, -1, 0, 0};
    private int[] dy = {0, 0, 1, -1};

    private boolean isSafe(int x, int y) {
        return ((x >= 0 && x < m) && (y >= 0 && y < n));
    }

    private int dfs(int i, int j, int[][] matrix, int[][] dp) {
        if(dp[i][j] != 0)  return dp[i][j];

        dp[i][j] = 1;

        for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if(isSafe(x, y) && matrix[x][y] > matrix[i][j]) {
                dp[i][j] = Math.max(dp[i][j], 1 + dfs(x, y, matrix, dp));
            }
        }
        return dp[i][j];
    }
    public int longestIncreasingPath(int[][] matrix) {
        m = matrix.length;
        n = matrix[0].length;
        int[][] dp = new int[m][n];

        int res = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res = Math.max(res, dfs(i, j, matrix, dp));
            }
        }

        return res;
    }
}