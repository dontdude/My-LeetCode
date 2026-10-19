class Solution {
    // number of subsets with given sum
    // rec(i, s)  // i = n -1 -> 0 and s = sum -> 0
    //     if i == 0 => s == 0 ? 1 : 0

    //     //take
    //     way += rec(i - 1, s - num[i])
        
    //     // not take
    //     way += rec(i - 1, s)

    // return way
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if(abs(target) > totalSum) return 0;
        if((totalSum + target) & 1) return 0;

        int subSetSum = (target + totalSum) / 2;

        // problem now is: number of subset with give sum
        vector<vector<int>> dp(n, vector<int>(subSetSum + 1, 0));

        dp[0][0] = 1;  // not take
        if(nums[0] <= subSetSum) dp[0][nums[0]] += 1;  // take

        for(int i = 1; i < n; i++) {
            for(int s = 0; s <= subSetSum; s++) {
                // take
                if(s >= nums[i]) dp[i][s] += dp[i - 1][s - nums[i]];

                // not take
                dp[i][s] += dp[i - 1][s];
            }
        }    

        return dp[n - 1][subSetSum];
    }
};