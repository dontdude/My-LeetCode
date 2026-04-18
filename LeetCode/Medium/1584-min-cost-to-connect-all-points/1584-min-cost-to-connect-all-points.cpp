class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<int> mst(n, -1);
        priority_queue<pair<int, int>> pq;

        pq.push({0, 0});
        int totalCost = 0;

        while(!pq.empty()) {
            int u = pq.top().second;
            int cost = -pq.top().first;
            pq.pop();

            if(mst[u] != -1)  continue;

            mst[u] = 0;
            totalCost += cost;

            for(int v = 0; v < n; v++) {
                if(mst[v] == -1) {
                    int distance = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    pq.push({-distance, v});
                }
            }  
        }

        return totalCost;
    }
};