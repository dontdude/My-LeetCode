class Solution {
public:
    // recurrence relation
    // rec(i, j)   // i = 0 -> n - 1    // j = n - 1 -> i
    //     if(i > j) return false
    //     if(i == j)  res++ return true
    //
    //     if(s[i] == s[j] && (j - i <= 2 || rec[i + 1][j - 1])) 
    //          res++;
    //          return true
    //     
    //     return false

    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int result = 0;

        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) { 
                if(s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {  
                    dp[i][j] = true;
                    result++;
                } 
            }
        }

        return result;
    }
};