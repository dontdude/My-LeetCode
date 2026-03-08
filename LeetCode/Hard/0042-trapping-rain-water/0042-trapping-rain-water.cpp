class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lmax = height[0], rmax = height.back();
        int water = 0;

        while(l <= r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            int moving;
            if(lmax < rmax) {
               moving = l;
               l++; 
            } else {
                moving = r;
                r--;
            }

            water += min(lmax, rmax) - height[moving];
        }

        return water;
    }
};