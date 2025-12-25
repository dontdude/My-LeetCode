class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n =  power.size();
        if(n == 1) return power[0];

        map<int, long long> count;

        for(int p : power) {
            count[p]++;
        }

        int size = 0;
        vector<int> unique_powers;
        for(pair<int, int> unique_power : count) {
            unique_powers.push_back(unique_power.first);
        }

        vector<long long> dp(unique_powers.size(), 0);
        dp[0] = unique_powers[0] * count[unique_powers[0]];

        for(int i = 1; i < unique_powers.size(); i++) {
            long long take = unique_powers[i] * count[unique_powers[i]];

            int j = i - 1;
            while(j >= 0 && unique_powers[j] > unique_powers[i] - 3)  j--;

            if(j >= 0)  take += dp[j];

            dp[i] = max(take, dp[i - 1]);
        }

        return dp.back();
    }
};