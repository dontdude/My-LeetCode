class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int minLen = INT_MAX;
        int left = 0, right = 0;
        int window = 0;

        while(right < n) {
            window += nums[right];
            right++;

            while(left < right && window >= target) {
                minLen = min(minLen, right - left);
                window -= nums[left];
                left++;
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};