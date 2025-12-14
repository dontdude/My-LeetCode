class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
       int n = nums.size();
        long long res = 0;

        sort(nums.begin(), nums.end());

        int med = n / 2;

        res += abs(nums[med] - k);
        nums[med] = k;

        int left = med - 1, right = med + 1;
        
        while(left >= 0 && nums[med] < nums[left]) {
            res += (long long)nums[left] - k;
            nums[left] = k;
            left--;
        }

        while(right < n && nums[med] > nums[right]) {
            res += (long long)k - nums[right];
            nums[right] = k;
            right++;
        }

        return res;
    }
};