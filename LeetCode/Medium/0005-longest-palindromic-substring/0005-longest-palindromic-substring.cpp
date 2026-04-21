class Solution {
    // recurrence relation
    // Checker :
    // rec(i, j)  // just checks i and j is palindromic or not
    //     if(i == j) return true;
    //     if(i > j)  return false;
    

    //     if(s[i] == s[j] && rec(i + 1, j - 1))  {
    //         if s(i, j) is ans -> res = substr(i, j)
    //         return true
    //     } 

    //     return false 

    // Explorer: i = 0 -> n - 1   ...  j = n - 1 -> 0
    // for i = 0 -> n - 1
    //     for j = n - 1 -> i
    //         rec(i, j)
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        string res = s.substr(0, 1); 

        for(int i = n - 1; i >= 0; i--) {

            for(int j = 0; j <= i; j++)  dp[i][j] = true; // base case 1 & b

            for(int j = i + 1; j < n; j++) {
                if(s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    
                    int len = j - i + 1;
                    if(res.size() < len) {
                        res = s.substr(i, len);
                    }
                }
            }
        }

        return res;
    }
};