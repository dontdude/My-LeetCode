class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<uint64_t> curr(amount + 1, 0);
        curr[0] = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= amount; j++) {
                if(coins[i] <= j) {
                    curr[j] += curr[j - coins[i]];
                }
            }
        }

        return curr[amount];
    }
};