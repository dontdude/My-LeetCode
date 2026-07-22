class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n + 1, 0); // number of NEW people who learn the secret on day i. 
        dp[1] = 1;
        int active_sharers = 0;
        int mod = 1e9 + 7;

        for(int i = 2; i <= n; i++) {
            if(i - delay > 0)  active_sharers = (active_sharers + dp[i - delay]) % mod;
            if(i - forget > 0) active_sharers = (active_sharers - dp[i - forget] + mod) % mod;
            dp[i] = active_sharers;
        }

        int knowsAtNthDay = 0;
        for(int i = n - forget + 1; i <= n; i++) {
            if(i > 0) knowsAtNthDay = (knowsAtNthDay + dp[i]) % mod;
        }

        return knowsAtNthDay;
    }
};