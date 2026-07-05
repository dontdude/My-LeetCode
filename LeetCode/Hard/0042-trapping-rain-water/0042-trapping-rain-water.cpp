class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int mxLeft = height[0], mxRight = height[n - 1];

        int water = 0;
        int left = 1, right = n - 2;

        while(left <= right) {
            if(mxLeft <= mxRight) {
                mxLeft = max(mxLeft, height[left]);
                water += mxLeft - height[left];
                left++;
            } else {
                mxRight = max(mxRight, height[right]);
                water += mxRight - height[right];
                right--;
            }
        }

        return water;
    }
};