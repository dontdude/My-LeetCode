class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int left = 0, right = height.size() - 1;

        while(left < right) {
            int len = min(height[left], height[right]);
            int wid = right - left;

            area = max(area, len * wid);

            height[left] < height[right] ? left++ : right--;
        }

        return area;
    }
};