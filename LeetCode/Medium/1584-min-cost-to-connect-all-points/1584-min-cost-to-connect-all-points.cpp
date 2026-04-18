class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> dist(n, vector<int>(n));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                dist[i][j] = dist[j][i] = distance;
            }
        }

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
                    pq.push({-dist[u][v], v});
                }
            }  
        }

        return totalCost;
    }
};