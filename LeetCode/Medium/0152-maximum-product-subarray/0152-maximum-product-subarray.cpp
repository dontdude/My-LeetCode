class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int leftPrd = 0, rightPrd = 0;

        int res = INT_MIN;

        for(int i = 0; i < n; i++) {
            int j = (n - 1) - i;

            if(leftPrd == 0)  leftPrd = nums[i];
            else leftPrd *= nums[i];

            if(rightPrd == 0)  rightPrd = nums[j];
            else rightPrd *= nums[j];

            res = max(res, max(leftPrd, rightPrd));
        }

        return res;
    }
};