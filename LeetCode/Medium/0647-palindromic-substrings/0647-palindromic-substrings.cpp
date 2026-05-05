class Solution {
public:
    // recurrence relation
    // rec(i, j)   // i = 0 -> n - 1    // j = n - 1 -> i
    //     if(i > j) return false
    //     if(i == j)  res++ return true
    //
    //     if(s[i] == s[j] && rec[i + 1][j - 1]) 
    //          res++;
    //          return true
    //     
    //     return false

    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
        int result = 0;

        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j <= n; j++) { 
                if(s[i] == s[j - 1] && (i + 1 >= j - 1 || dp[i + 1][j - 1])) {   // if compared charater were only contained 2 or less char already, or smaller string was palidrome.
                    dp[i][j] = true;
                    result++;
                    continue;
                } 

                dp[i][j] = false;
            }
        }

        return result;
    }
};