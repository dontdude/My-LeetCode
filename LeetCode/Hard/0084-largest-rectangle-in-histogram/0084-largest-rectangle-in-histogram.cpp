class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmaller(n), rightSmaller(n);
        stack<int> monotonicIncreasingStack;

        for(int i = 0; i < n; i++) {
            while(!monotonicIncreasingStack.empty() && heights[monotonicIncreasingStack.top()] >= heights[i]) {
                monotonicIncreasingStack.pop();
            }

            leftSmaller[i] = monotonicIncreasingStack.empty() ? -1 : monotonicIncreasingStack.top();
            monotonicIncreasingStack.push(i);
        }

        while(!monotonicIncreasingStack.empty())  monotonicIncreasingStack.pop();

        for(int i = n - 1; i >= 0; i--) {
            while(!monotonicIncreasingStack.empty() && heights[monotonicIncreasingStack.top()] >= heights[i]) {
                monotonicIncreasingStack.pop();
            }

            rightSmaller[i] = monotonicIncreasingStack.empty() ? n : monotonicIncreasingStack.top();
            monotonicIncreasingStack.push(i);
        }

        int res = 0;
        for(int i = 0; i < n; i++) {
            int breadth = heights[i];
            int length = rightSmaller[i] - leftSmaller[i] - 1;

            res = max(res, breadth * length); 
        } 

        return res;
    }
};