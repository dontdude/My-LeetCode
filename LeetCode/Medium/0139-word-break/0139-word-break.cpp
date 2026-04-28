class Solution {
    bool isPatternMatching(int start, int size, string& s, string& word) {
        if(start + size >  s.size()) return false;
        for(int i = 0; i < size; i++) {
            if(s[i + start] != word[i]) return false;
        }

        return true;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        vector<char> dp(n + 1, '0');
        dp[n] = '1';

        for(int i = n - 1; i >= 0; i--) {
            for(string word : wordDict) {
                int size = word.size();
                if((i + size) <= n && isPatternMatching(i, size, s, word)) {
                    if(dp[i + size] == '1') { 
                        dp[i] = '1';
                        break;
                    }
                }
            }
        }

        return dp[0] == '1';
    }
};