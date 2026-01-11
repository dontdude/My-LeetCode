class Solution {
public:
    struct PointDistance {
        int X;
        int Y;
        long long Distance;
    };
    struct compareDist {
        bool operator()(PointDistance & pd1, PointDistance & pd2) {
            return pd1.Distance > pd2.Distance;
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<PointDistance, vector<PointDistance>, compareDist> min_heap;

        for(vector<int> point: points) {
            long long d = (long long)point[0] * point[0] + (long long)point[1] * point[1];

            min_heap.push({point[0], point[1], d});
        }

        vector<vector<int>> res;
        while(k--) {
            PointDistance pd = min_heap.top();
            min_heap.pop();

            res.push_back({pd.X, pd.Y});
        }

        return res;
    }
};