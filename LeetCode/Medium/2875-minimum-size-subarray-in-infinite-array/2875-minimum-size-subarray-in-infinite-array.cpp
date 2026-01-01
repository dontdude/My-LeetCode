class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long sum = 0, n = nums.size();
        for(int num : nums)  sum += num;

        int append_times = target / sum;
        int sub_target = target % sum;

        int appended_size = n * append_times;
        if(sub_target == 0) {
            return appended_size;
        }

        vector<int> appended_nums = nums;
        appended_nums.insert(appended_nums.end(), nums.begin(), nums.end());

        int left = 0, right = 0;
        int curr_sum = 0;
        int min_subarr = INT_MAX;

        while(right < (2 * n)) {
            curr_sum += appended_nums[right];
            right++;

            while(curr_sum >= sub_target) {
                if(curr_sum == sub_target) {
                    min_subarr = min(min_subarr, right - left);
                }

                curr_sum -= appended_nums[left];
                left++;
            }
        }

        return min_subarr == INT_MAX ? -1 : min_subarr + appended_size;
    }
};