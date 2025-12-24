class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, n = nums.size(); 
        int sum = 0, res = INT_MAX;
        
        while(i < n) {
            sum += nums[i++];
            while(sum >= target) {
                sum -= nums[j++];
            }

            if(j > 0 && sum + nums[j-1] >= target)  res = min(res, i - j + 1);
        } 

        return res == INT_MAX ? 0 : res;
    }
};