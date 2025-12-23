class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, long long> count;
        for(int p : power) {
            count[p]++;
        }

        vector<int> unique_powers;
        for(auto c : count) {
            unique_powers.push_back(c.first);
        }

        int n = unique_powers.size();
        vector<long long> dp(n, 0);
        dp[0] = count[unique_powers[0]] * unique_powers[0]; 

        for(int i = 1; i < n; i++) {
            long long take = count[unique_powers[i]] * unique_powers[i];

            int j = i - 1;
            while(j > 0 && unique_powers[j] > unique_powers[i] - 3)   j--;
            if(unique_powers[j] <= unique_powers[i] - 3) {
                take += dp[j];
            }

            long long notTake = dp[i - 1];

            dp[i] = max(take, notTake);
        }

        return dp[n - 1];
    }
};