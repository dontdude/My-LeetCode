class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> treeMap;
        for(const auto& num: nums) {
            treeMap[num]++;
        }

        int n = treeMap.size();
        vector<int> dp(n, 0);
        int i = 0, prevVal = -1;

        for(const auto& it: treeMap) {
            int val = it.first;
            int pick = val * it.second;
            int not_pick = i > 0 ? dp[i - 1] : 0;
            
            if(val == prevVal + 1) {
                pick += (i > 1) ? dp[i - 2] : 0;  // skip prev
            } else {
                pick += (i > 0) ? dp[i - 1] : 0;
            }

            dp[i] = max(pick, not_pick);
            prevVal = val;
            i++;
        }

        return dp[n - 1];
    }
};