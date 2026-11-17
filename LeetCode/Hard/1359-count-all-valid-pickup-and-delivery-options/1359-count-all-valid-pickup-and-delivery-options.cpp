class Solution {
public:
    int countOrders(int n) {
        int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        for(int i = 1; i <= n; i++) {
            dp[i] = (dp[i - 1] * i * (2*i - 1)) % MOD;
        }

        return dp[n];
    }
};