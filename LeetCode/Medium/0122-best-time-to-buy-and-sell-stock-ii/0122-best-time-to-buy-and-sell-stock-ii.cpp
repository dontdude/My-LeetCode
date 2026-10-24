class Solution {
    // rec(i)   // i = n - 1 -> 0
    //     if(i == 0)  return 0;

    //     for(int j = 0; j < i; j++) 
    //         if(prices[i] > prices[j])  res = max(res, (prices[i] - prices[j]) + rec(j))
    //         else res = max(res, rec(j))

    //     return res
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int profit = prices[i] - prices[j];

                if(profit > 0)  dp[i] = max(dp[i], profit + dp[j]);
                else dp[i] = max(dp[i], dp[j]);
            }
        }

        return dp[n - 1];
    }
};