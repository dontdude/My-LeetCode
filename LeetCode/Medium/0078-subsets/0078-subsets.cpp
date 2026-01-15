class Solution {
public:
    void helper(int i, vector<int>& curr_sub, vector<vector<int>>& all_sub, vector<int>& nums) {
        if(i >= nums.size()) {
            all_sub.push_back(curr_sub);
            return;
        }

        // include
        curr_sub.push_back(nums[i]);
        helper(i + 1, curr_sub, all_sub, nums);

        // not include
        curr_sub.pop_back();
        helper(i + 1, curr_sub, all_sub, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr_subset;
        vector<vector<int>> all_subsets;

        helper(0, curr_subset, all_subsets, nums);

        return all_subsets;
    }
};