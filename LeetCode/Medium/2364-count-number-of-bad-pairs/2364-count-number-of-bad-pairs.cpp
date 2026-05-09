class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long badPairs = 0;
        unordered_map<int, int> goodPairs;

        for(int i = 0; i < n; i++) {
            int val = nums[i] - i;

            // i = total pairs seen till now
            badPairs += i - goodPairs[val];

            goodPairs[val]++; 
        }

        return badPairs;
    }
};