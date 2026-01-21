class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());

        int res = 0;
        for(int num : hash) {
            if(hash.find(num - 1) == hash.end()) {
                int len = 1;
                int nextNum = num + 1;

                while(hash.find(nextNum) != hash.end()) {
                    len++;
                    nextNum++;
                }

                res = max(res, len);
            }
        }

        return res;
    }
};