class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums, int x = 0) {
        res.push_back(nums);
        for(int i = x; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                swap(nums[i], nums[j]);
                permute(nums, i + 1);
                swap(nums[i], nums[j]);
            }
        }
        return res;
    }
};