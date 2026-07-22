class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfitRes = 0;
        vector<int> dp(n, 0); // dp[i] = max profit at day i
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int currProfit = prices[i] - prices[j];
                if(currProfit > 0) {
                    int lastMaxProfit = j - 2 >= 0 ? dp[j - 2] : 0;
                    maxProfitRes = max(maxProfitRes, currProfit + lastMaxProfit);
                }
            }
            dp[i] = maxProfitRes;
        }

        return maxProfitRes;
    }
};