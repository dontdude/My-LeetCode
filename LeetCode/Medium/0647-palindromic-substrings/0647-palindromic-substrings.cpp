class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));

        dp[n - 1][n - 1] = 1;
        int count = n;   // all single char are already palindrome

        for(int i = n - 2; i >= 0; i--) {
            dp[i][i] = 1;
            for(int j = i + 1; j < n; j++) {
                if(s[i] == s[j]) {
                    if(j - i <= 2 || dp[i + 1][j - 1] > 0) {  
                        dp[i][j] = 1;
                        count++;
                    }
                } 
            }
        }

        return count;
    }
};