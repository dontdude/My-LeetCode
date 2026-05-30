class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> diffHash;
        long long diffsTillNow = 0, pairs = 0;

        for(int i = 0; i < nums.size(); i++) {
            int diff = nums[i] - i;

            diffHash[diff]++;
            diffsTillNow++;

            pairs += diffsTillNow - diffHash[diff];
        }

        return pairs;
    }
};