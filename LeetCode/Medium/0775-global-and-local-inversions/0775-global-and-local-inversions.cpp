class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int mxtill = 0, n = nums.size();
        
        for(int i = 0; i < n - 2; i++) {
            mxtill = max(mxtill, nums[i]);
            if(mxtill > nums[i + 2]) {
                return false;
            }
        }

        return true;
    }
};