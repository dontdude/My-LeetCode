class Solution {
public:
    int countOrders(int n) {
        int mod = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
        dp[0][0] = 1;

        for(int p = 0; p <= n; p++) {
            for(int d = 0; d <= n; d++) {
                if(p > 0) dp[p][d] = (dp[p][d] + (p * dp[p - 1][d]) % mod) % mod;

                if(d > p) dp[p][d] = (dp[p][d] + ((d - p) * dp[p][d - 1]) % mod) % mod;
            }
        }

        return dp[n][n];
    }
};