class Solution {
public:
    int requiredKForThisSum(int poss_sum, vector<int>& nums) {
        int k_req = 1;
        int sum = 0;
        for(int num : nums) {
            if(sum + num <= poss_sum) {
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
            int sum = low + (high - low) / 2;

            if(requiredKForThisSum(sum, nums) <= k) {
                high = sum;
            } else {
                low = sum + 1;
            }
        }

        return low;
    }
};