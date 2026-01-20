class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int l = 0, r = n - 1;
        int lmax = height[l], rmax = height[r];

        int water = 0;
        while(l <= r) {
            int moving;
            if(height[l] < height[r]) {
                moving = height[l];
                l++;
            } else {
                moving = height[r];
                r--;
            }

            water += max(0, min(lmax, rmax) - moving);
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
        }

        return water;
    }
};