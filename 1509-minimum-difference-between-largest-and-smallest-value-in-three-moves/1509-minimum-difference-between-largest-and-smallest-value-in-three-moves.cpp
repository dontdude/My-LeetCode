class Solution {
public:
    void helper(int i, int j, vector<int>& nums, int& curMin, int counter = 1) {
        if(counter >= 3) {   
            curMin = min(curMin, min(nums[j-1] - nums[i], nums[j] - nums[i+1])); 
            return;
        }

        helper(i + 1, j, nums, curMin, counter + 1);
        helper(i, j - 1, nums, curMin, counter + 1);
    }
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4)  return 0;

        sort(nums.begin(), nums.end());

        int res = nums[n-1] - nums[0];
        helper(0, n-1, nums, res);

        return res;
    }
};