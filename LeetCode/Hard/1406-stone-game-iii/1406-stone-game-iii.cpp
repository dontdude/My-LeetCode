class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, INT_MIN);   // dp[i] = current player move's best score = (your_gain - opponent's_best_response)
        dp[n] = 0;

        for(int i = n - 1; i >= 0; i--) {
            int currPoints = 0;
            for(int j = 0; j < 3 && i + j < n; j++) {
                currPoints += stoneValue[i + j];
                dp[i] = max(dp[i], currPoints - dp[i + j + 1]);   // currPoints - next player best move
            }
        }

        return dp[0] == 0 ? "Tie" : (dp[0] < 0 ? "Bob" : "Alice");
    }
};