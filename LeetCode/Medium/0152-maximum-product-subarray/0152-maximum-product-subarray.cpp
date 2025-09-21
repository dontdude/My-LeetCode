class Solution {
public:
    // subarray traversal solution  (Not optimal takes 0(n2), but better than brute force o(n3))
    // int maxProduct(vector<int>& nums) {
    //     int res = INT_MIN, n = nums.size() - 1;

    //     for(int i = 0; i < n; i++) {
    //         int product = 1;
    //         for(int j = i; j < n; j++) {   // loop to traverse each sub array, startin from i and ending at j
    //             product = product * nums[j];
    //             res = max(res, product);
    //         }
    //     }

    //     return res;
    // }

    // observation of number of -ve number to be ignored based, and handling 0th occurence case (o(n))
    int maxProduct(vector<int>& nums) {
        int prefixPrd = 1, suffixPrd = 1; 
        int res = INT_MIN, n = nums.size();

        for(int i = 0; i < n; i++) {
            // handle fresh start, after encountering 1, in last iteration
            if(prefixPrd == 0)  prefixPrd = 1;
            if(suffixPrd == 0)  suffixPrd = 1;

            prefixPrd *= nums[i];
            suffixPrd *= nums[n - i - 1];

            res = max(res, max(prefixPrd, suffixPrd));
        }

        return res;
    }
};