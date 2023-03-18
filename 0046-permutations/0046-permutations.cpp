class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(0, nums);
        return res;
    }
    void backtrack(int x, vector<int>& nums){
        if(x == nums.size() - 1){
            res.push_back(nums);
            return;
        }

        for(int i = x; i < nums.size(); i++){
            swap(nums[x], nums[i]);
            backtrack(x + 1, nums);
            swap(nums[x], nums[i]);
        }
    }
};