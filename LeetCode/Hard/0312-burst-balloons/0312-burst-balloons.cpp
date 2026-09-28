class Solution {
    int helper(int l, int r, int& n, vector<vector<int>>& dp, vector<int>& nums) {
        if(l > r)  return 0;
        if(dp[l][r] != -1)  return dp[l][r];
        
        int mxPrd = 0;
        for(int i = l; i <= r; i++) {
            int curPrd = nums[i];
            if(l > 0)  curPrd *= nums[l - 1];
            if(r < n - 1)  curPrd *= nums[r + 1];

            if(i > l) curPrd += helper(l, i - 1, n, dp, nums);
            if(i < r) curPrd += helper(i + 1, r, n, dp, nums);

            mxPrd = max(mxPrd, curPrd);
        }

        return dp[l][r] = mxPrd;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return helper(0, n - 1, n, dp, nums);
    }
};