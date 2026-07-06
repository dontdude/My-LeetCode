class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<uint64_t> prev(amount + 1, 0), curr(amount + 1, 0);
        prev[0] = 1, curr[0] = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= amount; j++) {
                curr[j] = 0;
                if(coins[i] <= j) {
                    curr[j] = curr[j - coins[i]];
                }

                curr[j] += prev[j];
            }
            prev = curr;
        }

        return prev[amount];
    }
};