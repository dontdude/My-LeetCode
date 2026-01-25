class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> hash_map;

        for(int p: power) {
            hash_map[p]++;
        }

        vector<int> unique_power;
        for(auto pair : hash_map) {
            unique_power.push_back(pair.first);
        }

        int n = unique_power.size();
        sort(unique_power.begin(), unique_power.end());

        vector<long long> dp(n, 0);

        for(int i = 0; i < n; i++) {
            int j = i - 1;
            while(j >= 0 && unique_power[j] >= unique_power[i] - 2) {
                j--;
            }

            long long take = (long long)unique_power[i] * hash_map[unique_power[i]];
            take += j >= 0 ? dp[j] : 0;

            long long notTake = i > 0 ? dp[i - 1] : 0;

            dp[i] = max(take, notTake);
        }

        return dp[n - 1];
    }
};