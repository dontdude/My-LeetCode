class Solution {
public:
    // int dfs(int i, int j, int m, int n) {  // i = 0 -> m, j = 0 -> n
    //     if(i == m - 1 && j == n - 1) {
    //         return 1;
    //     }

    //     int paths = 0;
        
    //     if(i + 1 < m)  paths += dfs(i + 1, j, m, n);
    //     if(j + 1 < n)  paths += dfs(i, j + 1, m, n);

    //     return paths;
    // }

    // Tabulation
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {

                if(i == m - 1 && j == n - 1)  {
                    dp[i][j] = 1;
                    continue;
                }

                int paths = 0;
        
                if(i + 1 < m)  paths += dp[i + 1][j];
                if(j + 1 < n)  paths += dp[i][j + 1];

                dp[i][j] = paths;
            }
        }

        return dp[0][0];
    }
};