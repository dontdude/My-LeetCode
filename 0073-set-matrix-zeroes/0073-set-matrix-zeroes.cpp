class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;  
        // why col0 ? think of a case where any one element from 1st column(apart from 1st element) is 0, that means we will be going to make matrix[0][0] = 0,
        // but this will cause a problem as matrix[0][0] will now try to make all element of 1st row 0, even if no element originally in 1st row was 0
        // to solve this we will not be scanning the first column, not to know whether to make this column 0 or not, we will be using a col0
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i = 0; i < m; i++){       // Top Down way : making first element of that row and column state as 0
            if(matrix[i][0] == 0)  col0 = 0;
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0)    matrix[0][j] = matrix[i][0] = 0;
            }
        }

        for(int i = m - 1; i >= 0; i--){   // Bottom up way : to make sure we are not using previously made 0 in current loop, as state decider 
            for(int j = n - 1; j >= 1; j--){
                if(matrix[0][j] == 0 || matrix[i][0] == 0)    matrix[i][j] = 0;
            }
            if(col0 == 0)  matrix[i][0] = 0;  
        }
    }
};