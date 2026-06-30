class Solution {
    bool nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;

        while(i > 0 && nums[i - 1] > nums[i])  i--;
        if(i == 0)  return false;

        int j = n - 1;
        while(nums[j] < nums[i - 1])  j--;
        swap(nums[i - 1], nums[j]);

        reverse(nums.begin() + i, nums.end());
        return true;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curNums = nums;
        sort(curNums.begin(), curNums.end());

        do {
            res.push_back(curNums);
        } while(nextPermutation(curNums));

        return res;
    }
};