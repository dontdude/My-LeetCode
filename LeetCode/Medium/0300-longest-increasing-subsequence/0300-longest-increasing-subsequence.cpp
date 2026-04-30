class Solution {
public:
    // dp way
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size(), res = 1;
    //     vector<int> dp(n, 1);

    //     for(int i = 1; i < n; i++) {
    //         for(int j = i - 1; j >= 0; j--) {
    //             if(nums[i] > nums[j]) dp[i] = max(dp[i], 1 + dp[j]);
    //             res = max(res, dp[i];)
    //         }
    //     }

    //     return res;
    // }

    // binary search way
    int lengthOfLIS(vector<int>& nums) {
        vector<int> incrSubseq;

        for(int& num : nums) {
            if(incrSubseq.size() == 0 || incrSubseq.back() < num) {
                incrSubseq.push_back(num);
                continue;
            }

            int ind = lower_bound(incrSubseq.begin(), incrSubseq.end(), num) - incrSubseq.begin();
            incrSubseq[ind] = num;
        }

        return incrSubseq.size();
    }
};