class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = -1, one = 0, two = nums.size() - 1;

        while(one <= two) {
            if(nums[one] == 0) {
                zero++;
                swap(nums[zero], nums[one]);
            } else if(nums[one] == 2) {
                swap(nums[two], nums[one]);
                two--;
                one--;
            }

            one++;
        }
    }
};