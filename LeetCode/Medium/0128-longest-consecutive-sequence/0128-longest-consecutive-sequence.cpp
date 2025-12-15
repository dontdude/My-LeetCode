class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());

        for(int num : s) {
            if(s.find(num - 1) == s.end()) {
                int curr = 1;
                int n = num;

                while(s.find(n + 1) != s.end()) {
                    curr++;
                    n++;
                }

                res = max(res, curr);
            }
        }

        return res;
    }
};