class Solution {
public:
    bool isPossibleResult(vector<int>& nums, int k, int curr) {
        int sum = 0, count = 1, i = 0;
        while(i < nums.size() && count <= k) {
            if(sum + nums[i] <= curr) {
                sum += nums[i++];
            } else {
                sum = 0;
                count++;
            }
        }

        return (count <= k) && (i >= nums.size()); 
    }

    int splitArray(vector<int>& nums, int k) {
        int low = 0, high = 0;
        for(auto num : nums) {
            low = max(num, low);
            high += num;
        }

        int res = high;
        while(low <= high) {
            int possibleRes = (high - low) / 2 + low;

            if(isPossibleResult(nums, k, possibleRes)) {
              res = possibleRes;
              high = possibleRes - 1;
            } else {
              low  = possibleRes + 1;
            }
        }

        return res;
    }
};