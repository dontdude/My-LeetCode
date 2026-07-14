class Solution {
    // Recurrence relation
    // rec(i) i = n -> 1
    //     if(i == 0 || i == 1)  rec[i] = 1

    //     if(s[i - 1] != 0)  rec[i]  = rec[i - 1];

    //     if(isValidPair(i - 1, i - 2))  {
    //         rec[i] += rec[i - 2]
    //     }

    bool isValidPair(char curr, char prev) {
        return (prev == '1' || (prev == '2' && curr <= '6'));
    } 
public:
    int numDecodings(string s) {
        if(s[0] == '0')  return 0;

        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1, dp[1] = 1;

        for(int i = 2; i <= n; i++) {
            if(s[i - 1] != '0')  dp[i] = dp[i - 1];

            if(isValidPair(s[i - 1], s[i - 2])) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};