class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2)  return 0;

        int water = 0;

        int left = 0, right = n - 1;
        int leftMax = height[left], rightMax = height[right];

        while(left <= right) {
            if(height[left] < height[right]) {
                water += max(0, leftMax - height[left]);
                leftMax = max(leftMax, height[left]);
                left++;
            } else {
                water += max(0, rightMax - height[right]);
                rightMax = max(rightMax, height[right]);
                right--;
            }
        }

        return water;
    }
};