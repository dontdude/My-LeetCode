class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        int i = 0, n = intervals.size();

        while(i < n && intervals[i][1] < newInterval[0]) {  // Phase 1
            res.push_back(intervals[i++]);
        }

        if(i < n) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);   // current overlapping may have smaller start
            // not updating end, because it will fail if newInterval was our 1st going to be interval, levae it with while loop check
        }

        while(i < n && intervals[i][0] <= newInterval[1]) {  // phase 2
            newInterval[1] = max(newInterval[1], intervals[i++][1]);
        }

        res.push_back(newInterval);

        while(i < n) {  // phase 3
            res.push_back(intervals[i++]);  
        }

        return res;
    }
};