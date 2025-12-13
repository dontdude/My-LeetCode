class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if(size <= 2)  return 0;  

        int lmax = height[0], rmax = height[size - 1];
        int l = 0, r = size - 1;

        int res = 0;

        while(l <= r) {
            if(height[l] < height[r]) {
                lmax = max(lmax, height[l]);
                res += lmax - height[l];
                l++;
            } else {
                rmax = max(rmax, height[r]);
                res += rmax - height[r];
                r--;
            }
        }

        return res;
    }
};