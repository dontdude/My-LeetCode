class Solution {
public:
    int kadane(vector<int>& nums) {
        int max_sum_subarr = INT_MIN, curr_sum = 0;

        for(int num : nums) {
            curr_sum = max(curr_sum + num, num);
            max_sum_subarr = max(max_sum_subarr, curr_sum);
        }

        return max_sum_subarr;
    }
    int maxSubarraySumCircular(vector<int>& nums) {  
        int max_sum_subarr = kadane(nums);
        if(max_sum_subarr < 0)  return max_sum_subarr;    // all elem were negative, so max_sum_subarr will be smallest negative number, and our ans

        int total_arr_sum = 0;
        for(int & num : nums) {
            total_arr_sum += num;
            num *= -1;
        }

        int min_sum_subarr = -1 * kadane(nums);

        return max(max_sum_subarr, total_arr_sum - min_sum_subarr);    // max of either max subarr sum, or total sum - min sum subarr is our ans
    }
};