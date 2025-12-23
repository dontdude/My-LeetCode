class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(); 

        int windowStart = 0, windowEnd = 0, windowSum = 0;
        int minWindowLen = INT_MAX;

        while(windowEnd < n) {
            windowSum += nums[windowEnd++];
            
            while(windowSum >= target) {
                minWindowLen = min(minWindowLen, windowEnd - windowStart);
                windowSum -= nums[windowStart++];
            }
        }

        return minWindowLen != INT_MAX ? minWindowLen : 0; 
    }
};