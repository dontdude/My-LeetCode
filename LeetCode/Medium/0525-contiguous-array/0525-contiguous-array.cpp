class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int>  sum_hash;

        int sum = 0, res = 0;
        sum_hash[0] = -1;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 0 ? -1 : 1;

            if(sum_hash.find(sum) != sum_hash.end()) {
                res = max(res, i - sum_hash[sum]);
            } else {
                sum_hash[sum] = i;
            }
        }

        return res;
    }
};