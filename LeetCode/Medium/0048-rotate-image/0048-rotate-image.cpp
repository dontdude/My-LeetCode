class Solution {
    // The final matrix is basically.. row and column swapped, and each row element reversed
    
    void transpose(vector<vector<int>>& matrix) {
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void reverseRows(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            int l = 0, r = n - 1;

            while(l < r) {
                swap(matrix[i][l], matrix[i][r]);
                l++;
                r--;
            }
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        // Swap row and col (transpose)
        transpose(matrix);

        // Rever elements of each row
        reverseRows(matrix);
    }
};