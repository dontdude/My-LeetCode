class Solution {
    // recurrence relation:
    // rec(i, j):
    //   if(i < 0 || j < 0)  return 0; 
    //   if(a[i] == b[j]) {
    //     return 1 + rec(i - 1, j - 1)
    //   } else {
    //     return max(rec(i - 1, j), rec(i, j - 1))
    //   }
    // int lcs(string a, string b) {
    //     int m = a.size(), n = b.size();

    //     vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    //     for(int i = 1; i <= m; i++) {
    //         for(int j = 1; j <= n; j++) {
    //             if(a[i - 1] == b[j - 1]) {
    //                 dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
    //             } else {
    //                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    //             }
    //         }
    //     }

    //     return dp[m][n];
    // }
    int lcs(string a, string b) {
        int m = a.size(), n = b.size();

        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(a[i - 1] == b[j - 1]) {
                    curr[j] = max(curr[j], 1 + prev[j - 1]);
                } else {
                    curr[j] = max(curr[j - 1], prev[j]);
                }
            }
            prev = curr;
        }

        return prev[n];
    }

    int longestPalindromicSubseq(string s) {
        string revs = s;
        reverse(revs.begin(), revs.end());

        return lcs(s, revs);
    }
public:
    int minInsertions(string s) {
        return s.size() - longestPalindromicSubseq(s);
    }
};