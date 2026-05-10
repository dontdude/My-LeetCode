class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> dp(n, 0);
        dp[0] = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j] && abs(nums[i] - nums[j]) <= target) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        return dp[n - 1] - 1;
    }
};