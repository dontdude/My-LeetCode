class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       int n = nums.size();
       int l = 0, r = n - 1;

       while(l <= r) {
            int m = l + (r - l) / 2;

            int prev_num = m > 0 ? nums[m - 1] : -1;
            int next_num = m < (n - 1) ? nums[m + 1] : -1;

            if(nums[m] == prev_num) {
                if(m & 1)  l = m + 1;
                else r = m - 1;
            } else if(nums[m] == next_num) {
                if((m & 1) == 0)  l = m + 1;
                else r = m - 1;
            } else {
                return nums[m];
            }
       }

       return -1;
    }
};