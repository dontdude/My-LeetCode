class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev1 = 0, prev2 = nums[0];

        for(int i = 1; i < n; i++) {
            int curr = max(prev2, nums[i] + prev1);
            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
};