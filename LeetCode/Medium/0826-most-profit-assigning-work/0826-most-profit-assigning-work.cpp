class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size(), m = worker.size();

        vector<pair<int, int>> jobs;
        for(int i = 0; i < n; i++) {
            jobs.push_back({profit[i], difficulty[i]});
        }

        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int res = 0, w = m - 1, j = n - 1;
        while(w >= 0 && j >= 0) {
            if(worker[w] >= jobs[j].second) {
                res += jobs[j].first;
                w--;
            } else {
                j--;
            }
        }

        return res;
    }
};