class Solution {
public:
    // Credit for this intutive solution : Neetcode
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int l = 0, r = n - 1;

        while(l < r) {
            int t = l, b = r;  // since n * n

            for(int i = 0; i < (r - l); i++) {
                // store top left
                int topLeft = matrix[t][l + i];

                // move bottom left -> top left
                matrix[t][l + i] = matrix[b - i][l];

                // move bottom right -> bottom left 
                matrix[b - i][l] = matrix[b][r - i];

                // move top right -> bottom right
                matrix[b][r - i] = matrix[t + i][r];

                // move top left to -> top right
                matrix[t + i][r] = topLeft;
            }

            l++;
            r--;
        }
    }
};