class Solution {
    void solve(int i, vector<vector<int>>& res, vector<int>& nums) {
        int n = nums.size();
        if(i == n) {
            res.push_back(nums);
            return;
        }

        for(int j = i; j < n; j++) {
            swap(nums[i], nums[j]);
            solve(i + 1, res, nums);
            swap(nums[i], nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(0, res, nums);
        return res;
    }
};