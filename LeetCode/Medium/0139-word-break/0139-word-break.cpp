class Solution {
    bool isWordMatch(string& s, int& i, string& word) {
        int m = word.size(), n = s.size();

        if(i + m > n) return false;
        for(int j = 0; j < m; j++) {
            if(s[i + j] != word[j])  return false;
        }

        return true;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        vector<char> dp(n + 1, 0);
        dp[n] = 1;

        for(int i = n - 1; i >= 0; i--) {
            for(string& word : wordDict) {
                if(isWordMatch(s, i, word)) {
                    dp[i] |= dp[i + word.size()];
                }
            }
        }

        return dp[0];
    }
};