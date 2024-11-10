class Solution {
public:
    int binarySearchForLessThanHalf(vector<int>& curr, int target, bool isHalfCase) {
        int b = 0, e = curr.size() - 1;
        while(b <= e) {
            int m = b + (e - b) / 2;
            long long current = curr[m];
            if(isHalfCase) {
                current *= 2LL;
            }
            if(current < target) {
                b = m + 1;
            } else {
                e = m - 1;
            }
        }

        return e;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<int> sortedFromBehind;
        sortedFromBehind.push_back(nums[n - 1]);

        for(int i = n - 2; i >= 0; i--) {
            int count = binarySearchForLessThanHalf(sortedFromBehind, nums[i], true);
            int pos = binarySearchForLessThanHalf(sortedFromBehind, nums[i], false);
            res +=  count + 1;
            sortedFromBehind.insert(sortedFromBehind.begin() + pos + 1, nums[i]);
        }

        return res;
    }
};