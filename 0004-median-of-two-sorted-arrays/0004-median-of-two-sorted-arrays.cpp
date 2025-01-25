class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // if x = number of elements ocurring before and including median in sorted order from nums1
        // then (n + m + 1) / 2 - x (say y) = num of elem occuming before and including median from nums 2
        // to find x, do binary search on all possible length of nums1
        int n = nums1.size(), m = nums2.size();
        if(n > m)  return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = n;  

        while(low <= high) {
            int x = (high - low) / 2 + low;
            int y = (n + m + 1) / 2 - x;

            int left1 = (x <= 0) ? INT_MIN : nums1[x - 1];
            int right1 = (x >= n) ? INT_MAX : nums1[x];
            int left2 = (y <= 0) ? INT_MIN : nums2[y - 1];
            int right2 = (y >= m) ? INT_MAX : nums2[y];

            if(left1 <= right2 && left2 <= right1) {
                if((n + m) & 1) {  
                    return (double)max(left1, left2);
                } else {
                    return (double)(max(left1, left2) + min(right1, right2)) / 2;
                }
            } else if(left1 > right2) {
                high = x - 1;  // reduces x 
            } else {
                low = x + 1;   // reduces y
            }
        }

        return 0.0;
    }
};