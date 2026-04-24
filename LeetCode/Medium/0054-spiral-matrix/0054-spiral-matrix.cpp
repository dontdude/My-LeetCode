class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        vector<int> res;

        while(top <= bottom && left <= right) {
            // top left -> top right
            for(int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;

            // top right -> bottom right
            for(int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;

            // bottom right -> bottom left
            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            if(left <= right) {
                // bottom left -> top left
                for(int i = bottom; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return res;
    }
};