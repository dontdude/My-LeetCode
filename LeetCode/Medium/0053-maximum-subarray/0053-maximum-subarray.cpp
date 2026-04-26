class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN, sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum = max(sum + nums[i], nums[i]);
            result = max(result, sum);
        }

        return result;
    }
};