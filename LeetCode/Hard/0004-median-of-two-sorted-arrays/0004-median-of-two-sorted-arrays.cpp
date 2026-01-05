class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2)  return findMedianSortedArrays(nums2, nums1);  // cut1 should be from smaller array.. to make sure, cut2 is never negative

        int low = 0, high = n1;   // high = n1, to denote cut1 can happens after all elem of nums1 too

        while(low <= high) {
            int cut1 = low + (high - low) / 2;  // cut1 = number of elements contributing to the Left Half
            int cut2 = (n1 + n2 + 1) / 2 - cut1;  // with + 1, forced median to be on left

            int l1 = (cut1 > 0) ? nums1[cut1 - 1] : INT_MIN;
            int l2 = (cut2 > 0) ? nums2[cut2 - 1] : INT_MIN;

            int r1 = (cut1 < n1) ? nums1[cut1] : INT_MAX;
            int r2 = (cut2 < n2) ? nums2[cut2] : INT_MAX;

            if(l1 <= r2 && l2 <= r1) {
                if((n1 + n2) & 1) {
                    return (double)max(l1, l2);
                } else {
                    int median1 = max(l1, l2);
                    int median2 = min(r1, r2);
                    return (double)((median1 + median2) / 2.0);
                }
            } else if(l1 > r2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};