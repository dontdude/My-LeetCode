class Solution {
public:
    // Recurrence relation, with intution (sum / 2 will be the sum of each subset of s1 and s2, where sum is total sum of nums)
    // rec(i, j)  // i = 0 -> n - 1, j = s/2 -> 0
    //    if(j == 0)  return true;
    //    if(i >= n)  return false;

    //    bool res = rec(i + 1, j);
    //    if(j >= a[i])  res = res || rec(i + 1, j - a[i]); 

    // Tabulation
    // bool canPartition(vector<int>& nums) {
    //     int sum = 0;
    //     for(int num : nums)   sum += num;

    //     if(sum & 1)   return false;   // odd sum array can never partition to 2 equal sum subset

    //     int n = nums.size(), s = sum / 2;
    //     vector<vector<int>> dp(n + 1, vector<int>(s + 1, false));

    //     for(int i = 0; i <= n; i++)  dp[i][0] = true;  // base case

    //     for(int i = n - 1; i >= 0; i--) {
    //         for(int j = 1; j <= s; j++) {
    //             dp[i][j] = dp[i + 1][j];

    //             if(j >= nums[i]) {
    //                 dp[i][j] = dp[i][j] || dp[i + 1][j - nums[i]];
    //             }
    //         }
    //     }

    //     return dp[0][s];
    // }

    // Space Optimized
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums)   sum += num;

        if(sum & 1)   return false; 

        int n = nums.size(), s = sum / 2;
        vector<int> prev(s + 1, false), curr(s + 1, false);  // curr[j] = true means sum j is possible, with current considered nums array.

        curr[0] = prev[0] = true;  // base case

        for(int i = n - 1; i >= 0; i--) {
            for(int j = 1; j <= s; j++) {
                curr[j] = prev[j];

                if(j >= nums[i]) {
                    curr[j] = curr[j] || prev[j - nums[i]];
                }
            }

            prev = curr;
        }

        return prev[s];
    }
};