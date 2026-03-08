class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> hash(nums.begin(), nums.end());

        for(int num : hash) {
            if(hash.find(num - 1) == hash.end()) {
                int count = 1, next = num + 1;
                while(hash.find(next) != hash.end()) {
                    count++;
                    next++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};