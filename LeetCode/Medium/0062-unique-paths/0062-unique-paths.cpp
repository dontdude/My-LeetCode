class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0), curr(n, 0);
        prev[0] = 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                curr[j] = prev[j];
                if(j) curr[j] += curr[j - 1];
            }

            prev = curr;
        }

        return prev[n - 1];
    }
};