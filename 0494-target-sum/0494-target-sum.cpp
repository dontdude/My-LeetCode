class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0); 
        vector<vector<int>> dp(n, vector<int>(2*sum + 1, -1));    
        // 2*sum + 1 => since possible values we can reach on applying positive or negative signs to nums are [-sum, sum], 
        // Therefore using array of double size of sum, where :
        // 1. [0 to sum] index => represent positive target achieved till now 
        // 2. [sum + 1 to 2*sum] index => represent negative target achieved till now, to allow indexing 
        
        return backtrack(nums, dp, target, sum, 0, 0);
    }

    int backtrack(vector<int>& nums, vector<vector<int>>& dp, int target, int s, int i, int curr){
        if(i >= nums.size())  return curr == target ? 1 : 0;    // all nums with symbol applied, does curr sum reach target
        int j = curr;   
        if(curr < 0)  j = abs(curr) + s;                 // converting negative curr seen so far values to [sum + 1, 2*sum]

        if(dp[i][j] == -1){
            dp[i][j] =  backtrack(nums, dp, target, s, i + 1, curr - nums[i]);    // negative symbol
            dp[i][j] += backtrack(nums, dp, target, s, i + 1, curr + nums[i]);    // positive symbol 
        }

        return dp[i][j];
    }
};