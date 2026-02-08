class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;  

        // Notice the loops, we complete amount for one coin than move to other coin

        for(int i = 0; i < coins.size(); i++){         // dp for combination where all permutation are considered same eg. 1, 1, 2 is same as 2, 1, 1
            for(int j = 1; j <= amount; j++){
                if(j >= coins[i])  dp[j] += dp[j - coins[i]];
            }
        }

        return dp[amount];
    }
};