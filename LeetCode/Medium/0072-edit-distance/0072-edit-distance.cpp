class Solution {
public:
    // Recurrence Relation:
    // rec(i, j) {
    //     if i = 0  return j;  // j number of insertion
    //     if j = 0 return i;   // i number of deletion

    //     if(ith elem of word1 == jth elem of word2) return rec(i-1, j-1)
    //     else {
    //         return 1 + min(
    //             rec(i, j-1),  // inserting char in word1, then removing similar char from both string
    //             rec(i-1, j),  // Deleting char from word1, then calling another recursion for rest string check
    //             rec(i-1, j-1)  // replacing char in word1, then removing that char from both
    //         );
    //     }
    // }

    // Tabulation of above recurrence relation
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for(int i = 0; i <= n; i++)  dp[i][0] = i;
        for(int j = 1; j <= m; j++)  dp[0][j] = j;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
                }
            }
        } 

        return dp[n][m];
    }
};