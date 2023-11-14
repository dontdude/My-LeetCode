class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, vector<int>>> pq;
        for(auto point : points) {
           long long distSq = (point[0] * point[0]) + (point[1] * point[1]);
           pq.push({-distSq, point});   // negative distance to make it work like maxheap
        }

        vector<vector<int>> res;
        while(k-- && !pq.empty()) {
            auto curPoint = pq.top();  pq.pop();
            res.push_back(curPoint.second);
        }

        return res;
    }
};