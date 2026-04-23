class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product = INT_MIN, n = nums.size();
        int left = 1, right = 1;

        for(int i = 0; i < n; i++) {
            int j = n - i - 1;

            if(left == 0)  left = 1;
            if(right == 0) right = 1;

            left *= nums[i];
            right *= nums[j];

            product = max(product, max(left, right));
        }

        return product;
    }
};