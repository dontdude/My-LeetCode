class Solution {
public:
    // Recurrence relation:
    // rec(i, j)  // i = 0 -> n - 1 (i is the index of coins), j = a -> 0 (j is the amount here)
    //     if(j == 0)  return 0;  // base case
    //     if(j < 0 || i <= 0)  return INT_MAX;
           
           
    //     int dont_take = rec(i + 1, j)   // current coin not considered at all
    //     if(j >= c[i])  min (path, 1 + rec(i, j - c[i]))   // current coin considered, and maybe considered in future call too  
    //                

    //     if(path != INT_MAX)  return path
    //     return INT_MAX;

    // Tabulation (i = n - 1 -> 0, j = 0 -> a. 
    // why a + 1 size of dp col,  Now since, a + 1 size will mean.. dp form 0 to a amount (not a - 1 amount), thus using that
    // why n + 1 size of dp row.. the last row index i = n.. is for base case
    int coinChange(vector<int>& c, int a) {
        int n = c.size(); 
        vector<vector<int>> dp(n + 1, vector<int>(a + 1, 1e9));

        for(int i = 0; i <= n; i++)  dp[i][0] = 0; // base case

        for(int i = n - 1; i >= 0; i--) {
            for(int j = 1; j <= a; j++) {  // starting loop from 1, as j = 0 already handled in base case
               int dont_take = dp[i + 1][j];
            
                int take = 1e9;
                if(j >= c[i] && dp[i][j - c[i]] != 1e9) {
                    take = 1 + dp[i][j - c[i]];
                }
                
                dp[i][j] = min(take, dont_take);
            }
        }

        return dp[0][a] == 1e9 ? -1 : dp[0][a];
    }
};