class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int i = 0, j = 0;

        while(i < intervals.size()){
            int curStart = intervals[i][0], curEnd = intervals[i][1];
            while(i+1 < intervals.size() && curEnd >= intervals[i+1][0]){
                i++;
                curEnd = max(curEnd, intervals[i][1]);
            }

            intervals[j++] = {curStart, curEnd};
            i++;
        }
        intervals.resize(j);

        return intervals;
    }
};