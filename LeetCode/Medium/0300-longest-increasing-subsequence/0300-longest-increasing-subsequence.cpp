class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;

        for(const int& num : nums) {
            if(lis.size() == 0 || lis.back() < num) {
                lis.push_back(num);
                continue;
            }

            int pos = lower_bound(lis.begin(), lis.end(), num) - lis.begin();
            lis[pos] = num;
        }

        return lis.size();
    }
};