class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for(int &  num : nums) {
            if(num < 0)  num = 0;
        }

        for(int i = 0; i < n; i++) {
            int ind = abs(nums[i]) - 1;
            if(ind >= n || ind < 0)  continue;

            if(nums[ind] == 0) {
                nums[ind] = -1 * (n + 1);
            } else {
                nums[ind] *= -1;
            }
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] >= 0) {
                return i + 1;
            }
        }

        return n + 1;
    }
};