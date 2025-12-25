class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return 0;

        int current_end = 0, farthest = 0;
        int jumps = 0;  // we update jump in the end of each level (that is reaching current_end)

        for(int i = 0; i < n; i++) {
            farthest = max(farthest, i + nums[i]);

            if(i == current_end) {
                jumps++;
                current_end = farthest;

                if(current_end >= n - 1)  break;
            }
        }

        return jumps;
    }
};