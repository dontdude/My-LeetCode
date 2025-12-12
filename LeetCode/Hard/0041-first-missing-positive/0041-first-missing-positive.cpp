class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // we will negate the value at that index, to mark that index vis
        // before this, we will be changing the negative integers to 0, so they don't interfere
        // if a value at a index is already 0, then to negate we will use -(size of nums + 1)
        // so any negative value.. will basically tell his index is a valid number already in array

        int size = nums.size(), i = 0;

        for(i = 0; i < size; i++) {
            if(nums[i] < 0)  nums[i] = 0;   // remove every negative value.. with zero
        }
        
        for(i = 0; i < size; i++) {
            int num_index = abs(nums[i]) - 1;
            if(num_index >= 0 && num_index < size) {
                if(nums[num_index] == 0) {   // to make the index presence.. make that zero stored at num index.. such a large negative value.. that we never process it's index. 
                    nums[num_index] = -1 * (size + 1);
                } else if(nums[num_index] > 0) {  // only negate if already not negated, to mark presence
                    nums[num_index] *= -1;
                }
            }
        }


        for(i = 0; i < size; i++) {
            if(nums[i] >= 0)  return i + 1;
        }

        return i + 1;
    }
};