class Solution {
    static bool comparator(vector<int>& a, vector<int>& b) {
        return (a[1] == b[1]) ? a[0] < b[0] : a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator);

        int skippedOverlap = 0, prevEnd = -(5 * 1e4) - 1;

        for(int i = 0; i < intervals.size(); i++) {
            if(intervals[i][0] >= prevEnd) {
                prevEnd = intervals[i][1];
            } else {
                skippedOverlap++;
            }
        }

        return skippedOverlap;
    }
};