class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n, 1);
        int prevPrefixPrd = 1, prevSuffixPrd = 1;

        for(int i = 1; i < n; i++) {
            int currPrefixPrd = nums[i - 1] * prevPrefixPrd;
            result[i] *= currPrefixPrd;
            prevPrefixPrd = currPrefixPrd;

            int currSuffixPrd = nums[n - i] * prevSuffixPrd;
            result[n - i - 1] *=  currSuffixPrd;
            prevSuffixPrd = currSuffixPrd;
        }

        return result;
    }
};