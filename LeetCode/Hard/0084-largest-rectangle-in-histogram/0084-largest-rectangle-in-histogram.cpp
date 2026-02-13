class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // we require next smaller for each (on both side), so using mis (monotonic increasing stack)
        stack<int> mis_left, mis_right;

        int n = heights.size();
        vector<int> next_smaller_left(n), next_smaller_right(n);

        for(int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
            while(mis_left.empty() == false && heights[mis_left.top()] >= heights[j]) {
                mis_left.pop();
            }

            while(mis_right.empty() == false && heights[mis_right.top()] >= heights[i]) {
                mis_right.pop();
            }

            next_smaller_left[j] = mis_left.empty() ? n : mis_left.top();
            next_smaller_right[i] = mis_right.empty() ? -1 : mis_right.top(); 

            mis_left.push(j);
            mis_right.push(i);
        }

        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            int breadth = heights[i];
            int length = next_smaller_left[i] - next_smaller_right[i] - 1;
            maxArea = max(maxArea, length * breadth);
        }

        return maxArea;
    }
};