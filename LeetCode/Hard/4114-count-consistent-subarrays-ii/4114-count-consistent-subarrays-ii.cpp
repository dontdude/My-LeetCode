class Solution {
public:
    long long countConsistent(vector<int>& nums) {
        int n = nums.size();

        stack<int> lmis, rmis;
        vector<long long> lwall(n, -1), rwall(n, n); 

        for(int i = 0; i < n; i++) {
            // left wall
            while(!lmis.empty() && (nums[lmis.top()] != nums[i]) && (nums[lmis.top()] & nums[i]) == nums[i]) {
                lmis.pop();
            }

            if(!lmis.empty()) lwall[i] = lmis.top();
            lmis.push(i);

            // right wall
            while(!rmis.empty() && (nums[rmis.top()] & nums[n - 1 - i]) == nums[n - 1 - i]) {
                rmis.pop();
            }

            if(!rmis.empty()) rwall[n - 1 - i] = rmis.top();
            rmis.push(n - 1 - i);  
        }

        long long subArr = 0;
        for(int i = 0; i < n; i++) {
            subArr += (i - lwall[i]) * (rwall[i] - i);
        }

        return subArr;
    }
};