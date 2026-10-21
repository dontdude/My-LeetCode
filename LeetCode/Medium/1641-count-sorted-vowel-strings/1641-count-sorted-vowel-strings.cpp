class Solution {
    // rec(i, v)  // i = n -> 1 & v = 0 -> 4
    //     if(i == 0)  return 1

    //     for(nextV = v -> 4) {
    //         ways += rec(i - 1, nextV)
    //     }

    //     return ways

public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(5));

        for(int v = 0; v < 5; v++)  dp[0][v] = 1;

        for(int i = 1; i <= n; i++) {
            for(int v = 4; v >= 0; v--) {
                for(int nextv = v; nextv <= 4; nextv++) {
                    dp[i][v] += dp[i - 1][nextv];
                }
            }
        }

        return dp[n][0];
    }
};