class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        int MOD = 1e9 + 7;

        stack<int> lmis, rmis;
        vector<long long> lwall(n, -1), rwall(n, n); 

        for(int i = 0; i < n; i++) {
            // left wall
            while(!lmis.empty() && nums[lmis.top()] > nums[i]) {
                lmis.pop();
            }

            if(!lmis.empty()) lwall[i] = lmis.top();
            lmis.push(i);

            // right wall
            while(!rmis.empty() && nums[rmis.top()] >= nums[n - 1 - i]) {
                rmis.pop();
            }

            if(!rmis.empty()) rwall[n - 1 - i] = rmis.top();
            rmis.push(n - 1 - i);  
        }

        long long minSums = 0;
        for(int i = 0; i < n; i++) {
            long long count = ((i - lwall[i]) * (rwall[i] - i)) % MOD;
            long long contrib = (nums[i] * count) % MOD;
            minSums = (minSums + contrib) % MOD;
        }

        return minSums;
    }
};