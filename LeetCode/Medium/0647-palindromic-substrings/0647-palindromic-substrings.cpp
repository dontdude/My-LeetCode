class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<char>> dp(n, vector<char>(n, 0));

        int palindromes = 0;

        for(int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            palindromes++;

            for(int j = i + 1; j < n; j++) {
                if(s[i] == s[j] && ((i + 1 == j) || dp[i + 1][j - 1])) {
                    dp[i][j] = 1;
                    palindromes++;
                }   
            }
        }

        return palindromes;
    }
};