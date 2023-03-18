class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(0, nums);
        return res;
    }
    void backtrack(int x, vector<int>& nums){
        res.push_back(nums);
        for(int i = x; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                swap(nums[i], nums[j]);
                backtrack(i+1, nums);
                swap(nums[i], nums[j]);
            }
        }
    }
};