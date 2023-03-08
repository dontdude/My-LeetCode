class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int col = 0; col < n; col++){        // Reverse each column
            int f = 0, l = n - 1;
            while(f < l)  swap(matrix[f++][col], matrix[l--][col]);
        }

        for(int i = 0; i < n - 1; i++){              // Transpose
            for(int j = i + 1; j < n; j++)   swap(matrix[i][j], matrix[j][i]);
        }
    }
};