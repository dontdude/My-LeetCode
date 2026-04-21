class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX));

        for(int i = n - 1; i >= 0; i--) {
            dp[i][0] = 0;

            for(int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i + 1][j];

                int rest = j - coins[i];
                if(rest >= 0 && dp[i][rest] != INT_MAX) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][rest]);
                }
            }
        }

        return dp[0][amount] == INT_MAX ? -1 : dp[0][amount];
    }
};