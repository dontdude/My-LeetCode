class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return 0;

        int min_jumps = 0;
        int current_end = 0, farthest = 0;

        for(int i = 0; i < n; i++) {
            farthest = max(farthest, i + nums[i]);

            if(i == current_end) {
                current_end = farthest;
                min_jumps++;

                if(current_end >= n - 1)  break;
            }
        }

        return min_jumps;
    }
};