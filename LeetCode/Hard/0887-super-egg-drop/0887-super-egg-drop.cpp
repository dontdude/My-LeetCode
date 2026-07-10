class Solution {
public:
    int superEggDrop(int k, int n) {
        if(k == 1 || n == 1) return n;

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));

        for(int i = 0; i <= n; i++) {
            for(int j = 1; j <= k; j++) {
                if(i <= 1 || j == 1) {
                    dp[i][j] = i;
                    continue;
                }

                int low = 1, high = i;
                while(low <= high) {
                    int f = low + (high - low) / 2;

                    int breakCase = dp[f - 1][j - 1];
                    int surviveCase = dp[i - f][j];

                    int worstCase = max(breakCase, surviveCase);
                    dp[i][j] = min(dp[i][j], 1 + worstCase);

                    if(breakCase <= surviveCase) { // can take more risk
                        low = f + 1;
                    } else {
                        high = f - 1;
                    }
                }
            }
        }

        return dp[n][k];
    }
};