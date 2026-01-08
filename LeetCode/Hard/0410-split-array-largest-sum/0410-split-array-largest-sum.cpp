class Solution {
public:
    int requiredK(int test_sum, vector<int>& nums) {
        int k_req = 1, sum = 0;

        for(int num : nums) {
            if(sum + num <= test_sum) {
                sum += num;
            } else {
                k_req++;
                sum = num;
            }
        }

        return k_req;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = 0, high = 0;
        for(int num : nums) {
            low = max(low, num);
            high += num;
        }

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(requiredK(mid, nums) <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};