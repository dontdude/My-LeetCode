class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int, int> countThisSumOcc;
        countThisSumOcc[0] = 1;     // with sum = 0, we mean that current sum of elements in array has become => k
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(countThisSumOcc.find(sum - k) != countThisSumOcc.end()) {
                res += countThisSumOcc[sum - k];
            }
            countThisSumOcc[sum]++;
        }
        return res;
    }
};