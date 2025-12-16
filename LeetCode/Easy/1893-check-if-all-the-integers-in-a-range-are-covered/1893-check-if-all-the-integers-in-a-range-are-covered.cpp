class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> range1D(52, 0);

        for(auto range: ranges) {
            range1D[range[0]] = 1;
            range1D[range[1] + 1] = -1;
        }

        for(int i = 1; i <= 50; i++) {
            range1D[i] += range1D[i - 1];
        }

        for(int i = left; i <= right; i++) {
            if(range1D[i] == 0)  return false;
        }

        return true;
    }
};