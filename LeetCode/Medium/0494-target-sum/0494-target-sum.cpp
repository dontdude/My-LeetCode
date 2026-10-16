class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<unordered_map<int, int>> dp(n);

        dp[0][nums[0]] += 1;
        dp[0][-nums[0]] += 1;

        for(int i = 1; i < n; i++) {
            for(const auto& [s, w] : dp[i - 1]) {
                dp[i][s + nums[i]] += w;
                dp[i][s - nums[i]] += w;
            }
        }

        return dp[n - 1][target];
    }
};