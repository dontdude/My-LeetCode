class Solution {
public:
    // recureence relation:
    // rec(i) 
        // if(i == 0) return 1;

        // int mxLen = 1;
        // for(int j = 0; j < i; j++) {
        //     if(nums[j] > nums[i])  mxLen = max(mxLen, rec(j) + 1)
        // }
        // res = max(res, mxLen)
        // return mxLen
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int res = 1;
        for(int i = 0; i < n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }

        
        return res;
    }
};