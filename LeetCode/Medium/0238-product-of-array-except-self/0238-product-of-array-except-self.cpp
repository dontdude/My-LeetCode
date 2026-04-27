class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixPrd(n, 1), suffixPrd(n, 1);

        for(int i = 1; i < n; i++) {
            prefixPrd[i] = nums[i - 1] * prefixPrd[i - 1];
            suffixPrd[n - i - 1] = nums[n - i] * suffixPrd[n - i];
        }

        for(int i = 0; i < n; i++) {
            prefixPrd[i] *= suffixPrd[i];
        }

        return prefixPrd;
    }
};