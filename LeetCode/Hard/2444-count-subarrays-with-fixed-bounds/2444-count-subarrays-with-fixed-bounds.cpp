class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int badPos = -1;
        int maxPos = -1;
        int minPos = -1;

        long long res = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < minK || nums[i] > maxK) {
                badPos = i;
            }

            if(nums[i] == maxK) maxPos = i;
            if(nums[i] == minK) minPos = i;

            int validSubarrays = min(minPos, maxPos) - badPos;

            if(validSubarrays > 0)  res += validSubarrays;
        }

        return res;
    }
};