class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long pairs = 0;
        vector<int> count(24, 0);

        for(int hour : hours) {
            int rem = hour % 24;
            int targetRem = (24 - rem) % 24;   // % 24, because.. if the rem was 0, then in that case, it needs targetRem as 0 too.

            pairs += count[targetRem];
            count[rem]++;
        }

        return pairs;
    }
};