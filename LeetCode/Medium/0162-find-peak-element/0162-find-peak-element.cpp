class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       int n = nums.size();
       int l = 0, r = n - 1;

       while(l <= r) {
            int m = l + (r - l) / 2;

            int prev_num = m > 0 ? nums[m - 1] : INT_MIN;  
            int next_num = m < (n - 1) ? nums[m + 1] : INT_MIN;
            
            if(prev_num < nums[m] && next_num < nums[m]) {
                return m;
            } else if(prev_num > nums[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
       }

       return -1;
    }
};