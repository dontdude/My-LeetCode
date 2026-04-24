class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool top = false, bottom = false, left = false, right = false;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {  
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;

                    if(i == 0 && !top)  top = true;
                    if(i == m - 1 && !bottom) bottom = true;
                    if(j == 0 && !left) left = true;
                    if(j == n - 1 && !right) right = true;
                }
            }
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(top || bottom) {
            for(int j = 0; j < n; j++) {
                if(top)    matrix[0][j] = 0;
                if(bottom) matrix[m - 1][j] = 0;
            }
        }

        if(left || right) {
            for(int i = 0; i < m; i++) {
                if(left)    matrix[i][0] = 0;
                if(right)   matrix[i][n - 1] = 0;
            }
        }
    }
};