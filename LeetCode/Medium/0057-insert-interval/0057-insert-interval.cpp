class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        int i = 0, n = intervals.size();
        bool inserted = false;

        while(i < n) {
            if(newInterval[0] <= intervals[i][1] && inserted == false) {
                if(newInterval[1] < intervals[i][0]) {
                    res.push_back(newInterval);
                    res.push_back(intervals[i]);
                    inserted = true;
                } else {
                    vector<int> mergedInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};

                    while(i + 1 < n && mergedInterval[1] >= intervals[i + 1][0]) {
                        mergedInterval[1] = max(mergedInterval[1], intervals[i + 1][1]);
                        i++;
                    }

                    res.push_back(mergedInterval);
                    inserted = true;
                }
            } else {
                res.push_back(intervals[i]);
            }

            i++;
        }

        if(inserted == false) {
            res.push_back(newInterval);
        } 

        return res;
    }
};