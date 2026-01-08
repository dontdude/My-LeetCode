class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        if(n1 > n2)  return findMedianSortedArrays(nums2, nums1);

        int low =  0, high = n1;
        while(low <= high) {
            int x = low + (high - low) / 2;
            int y = (n1 + n2 + 1) / 2 - x;

            int l1 = (x > 0) ? nums1[x - 1] : INT_MIN;
            int l2 = (y > 0) ? nums2[y - 1] : INT_MIN;

            int r1 = (x < n1) ? nums1[x] : INT_MAX;
            int r2 = (y < n2) ? nums2[y] : INT_MAX;

            if(l1 < r2 && l2 < r1) {
                if((n1 + n2) & 1) {
                    return (double)max(l1, l2);
                } else {
                    int median1 = max(l1, l2);
                    int median2 = min(r1, r2);
                    return (double)((median1 + median2) / 2.0);
                }
            } else if(l1 > r2) {
                high = x - 1;
            } else {
                low = x + 1;
            }
        }

        return 0.0;
    }
};