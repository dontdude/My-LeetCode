class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroInd = -1, oneInd = 0, twoInd = nums.size() - 1;

        while(oneInd <= twoInd) {
            if(nums[oneInd] == 1) {
                oneInd++;
            } else if(nums[oneInd] == 0) {
                swap(nums[zeroInd + 1], nums[oneInd]);
                oneInd++;
                zeroInd++;
            } else {
                swap(nums[twoInd], nums[oneInd]);
                twoInd--;
            }
        }
    }
};