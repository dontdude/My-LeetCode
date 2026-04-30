class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> left_mis, right_mis;
        vector<int> left_smaller(n), right_smaller(n);

        for(int i = 0; i < n; i++) {
            while(!left_mis.empty() && heights[left_mis.top()] >= heights[i]) {
                left_mis.pop();
            }

            int j = n - 1 - i;
            while(!right_mis.empty() && heights[right_mis.top()] >= heights[j]) {
                right_mis.pop();
            }

            if(left_mis.empty()) left_smaller[i] = -1;
            else left_smaller[i] = left_mis.top();

            if(right_mis.empty()) right_smaller[j] = n;
            else right_smaller[j] = right_mis.top();

            left_mis.push(i);
            right_mis.push(j);
        }

        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            int len = heights[i];
            int wid = right_smaller[i] - left_smaller[i] - 1;
            maxArea = max(maxArea, len * wid);
        }

        return maxArea;
    }
};