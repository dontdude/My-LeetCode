class Solution {
public:
    bool search(vector<int>& nums, int target) {
       // In this version of rotated soted array, since certain elements can be similar, a case may arise where nums[left] == nums[mid] == nums[right],
       // for example : nums = {1, 0, 1, 1, 1, 1, 1} target = 0
       // than in that case, the binary search can't tell which partition to chose for next iteration, so for that case :
       // since nums[mid] already checked, and it's not the target, so nums[left] and nums[right] are not the target either, so in this iteration just remove these left and right value from consideration and move to there next values i.e, left++ and right--

       int left = 0, right = nums.size() - 1;

       while(left <= right){
           int mid = left + (right - left) / 2;

           if(nums[mid] == target)  return true;

           if(nums[left] == nums[mid] && nums[mid] == nums[right]){  // linearly iterating to next left, right value
               left++;
               right--;
           } else if(nums[left] <= nums[mid]) {         // left partition is sorted, 
           // now why left partition is sure sorted even when nums[left] == nums[mid] is true here, because nums[mid] != nums[right] that means nums[right] < nums[mid] in every case
                if(nums[left] <= target && target < nums[mid])  right = mid - 1;
                else left = mid + 1;
           } else {                                   // Right partition is sorted
               if(nums[mid] < target && target <= nums[right])  left = mid + 1;
               else right = mid - 1;
           }
       }   

       return false;
    }
};