class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sum_hash;
        sum_hash[0]++;

        int sum = 0, res = 0;
        for(int num : nums) {
            sum += num;
            int target = sum - k;

            if(sum_hash.find(target) != sum_hash.end()) {
                res += sum_hash[target];
            }

            sum_hash[sum]++;
        }

        return res;
    }
};