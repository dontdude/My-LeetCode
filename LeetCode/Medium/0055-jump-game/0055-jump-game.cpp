class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)  return true;

        int nextJump = 0, currEnd = 0, jumps = 0;

        for(int i = 0; i < n && currEnd < n - 1; i++) { 
            nextJump = max(nextJump, i + nums[i]);
            
            if(i == currEnd) {
                if(nextJump <= currEnd) return false;  
                jumps++;
                currEnd = nextJump;
            }
        }

        return currEnd >= n-1;
    }
};