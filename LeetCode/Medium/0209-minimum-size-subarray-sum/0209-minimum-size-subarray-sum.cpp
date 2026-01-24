class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;

        int res = INT_MAX, curr_sum = 0;

        while(r < nums.size()) {
            curr_sum += nums[r];
            r++;

            while(curr_sum >= target) {
                res = min(res, r - l);
                curr_sum -= nums[l];
                l++;
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};