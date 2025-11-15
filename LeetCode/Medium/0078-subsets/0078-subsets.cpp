class Solution {
vector<vector<int>> res;
public:
    void dfs(int index, vector<int> currSubset, vector<int>& nums) {
        if(index == nums.size()) {
            res.push_back(currSubset);
            return;
        }

        dfs(index + 1, currSubset, nums);   // next with current number not included

        currSubset.push_back(nums[index]);
        dfs(index + 1, currSubset, nums);   // next with current number included
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, vector<int>(), nums);
        return res;
    }
};