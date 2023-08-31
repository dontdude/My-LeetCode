class Solution {
public:
    bool divideAndConquer(int sr, int sc, int er, int ec, vector<vector<int>>& matrix, int target) {
        if(sr > er || sc > ec)   return false;

        int mr = (er + sr) / 2, mc = (ec + sc) / 2;

        if(matrix[mr][mc] == target)  return true;
        else if(matrix[mr][mc] > target) {
            return divideAndConquer(sr, sc, er, mc-1, matrix, target) || divideAndConquer(sr, mc, mr-1, ec, matrix, target);
        } else {
            return divideAndConquer(sr, mc+1, er, ec, matrix, target) || divideAndConquer(mr+1, sc, er, mc, matrix, target);
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        return divideAndConquer(0, 0, n-1, m-1, matrix, target);
    }
};