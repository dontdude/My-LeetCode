class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int mini = -1, maxi = -1, badPos = -1;

        long long subarrs = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < minK || nums[i] > maxK) {
                badPos = i;
                mini = -1;
                maxi = -1;
            }

            if(nums[i] == minK)  mini = i;
            if(nums[i] == maxK)  maxi = i;

            int count = min(mini, maxi) - badPos;
            subarrs += max(count, 0);
        }

        return subarrs;
    }
};