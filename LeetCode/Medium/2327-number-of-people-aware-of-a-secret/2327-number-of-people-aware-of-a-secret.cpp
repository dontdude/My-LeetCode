class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long mod = 1e9 + 7;
        vector<long> dp(n, 0);  // number of people that can share secret at an i day (not all those who knows)
        dp[0] = 1;

        long canShare = 0;

        for(int i = 1; i < n; i++) {
            long newShare = (i >= delay) ? dp[i - delay] : 0;
            long peopleForgetting = (i >= forget) ? dp[i - forget] : 0;

            canShare = (canShare + newShare - peopleForgetting + mod) % mod;

            dp[i] = canShare;
        }

        long knows = 0;
        for(int i = max(n - forget, 0); i < n; i++) {   // start from first date, whose canshare people not forgetten at nth day.
            knows = (knows + dp[i]) % mod;
        }

        return knows;
    }
};